#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include QMK_KEYBOARD_H

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

#ifdef MATRIX_MASKED
    extern const matrix_row_t matrix_mask[];
#endif

// this keyboard uses a BCD to select row to read value, the column pins are actually input pins, pulled high on default
static const pin_t row_selector[MATRIX_ROW_SEL_BITS] = MATRIX_ROW_SEL_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

/* matrix state(1:on, 0:off) */
static matrix_row_t raw_matrix[MATRIX_ROWS]; //raw values
static matrix_row_t matrix[MATRIX_ROWS]; //debounced values

inline
uint8_t matrix_rows(void) {
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void) {
    return MATRIX_COLS;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

/*　`matrix_io_delay ()` exists for backwards compatibility. From now on, use matrix_output_unselect_delay().　*/
__attribute__((weak)) void matrix_io_delay(void) {
    wait_us(MATRIX_IO_DELAY);
}
__attribute__((weak)) void matrix_output_select_delay(void) {
    waitInputPinDelay();
}
__attribute__((weak)) void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    matrix_io_delay();
}

// user-defined overridable functions

__attribute__((weak)) void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__((weak)) void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}


inline
matrix_row_t matrix_get_row(uint8_t row)
{
    // Matrix mask lets you disable switches in the returned matrix data. For example, if you have a
    // switch blocker installed and the switch is always pressed.
#ifdef MATRIX_MASKED
    return matrix[row] & matrix_mask[row];
#else
    return matrix[row];
#endif
}

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline uint8_t readMatrixPin(pin_t pin) {
    if (pin != NO_PIN) {
        return readPin(pin);
    } else {
        return 1;
    }
}

void matrix_print(void)
{
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_hex8(row); print(": ");
        print_matrix_row(row);
        print("\n");
    }
}


// Writes a BCD value to the keyboard's decoder chips
// e.g. line 7 is written as 0111 to the BCD decoder
// and pulls pin to ground enabling column input measurement
//
// NEC board uses enable pins on decoder, but the strobe is inverted (twice)
static bool select_row(uint8_t line) {
  int mask = 1;
  for (uint8_t i = 0; i < MATRIX_ROW_SEL_BITS - 1; i++) {
    (line & mask) ? setPinOutput_writeHigh(row_selector[i])
    : setPinOutput_writeLow(row_selector[i]);
    mask <<= 1;
  }

  // Invert the strobe output (last bit/BCD selector)
  (line & mask) ? setPinOutput_writeLow(row_selector[MATRIX_ROW_SEL_BITS-1])
  : setPinOutput_writeHigh(row_selector[MATRIX_ROW_SEL_BITS-1]);

  //TODO: in case keyboard has unused rows
  return true;
}

// No need for another function to unselect all, clearing decoder
// outputs will flush any selected row (write 0b1111)
static void unselect_row(void){
    //initialise row selector, default row 0
    for (uint8_t i = 0; i < MATRIX_ROW_SEL_BITS; i++){
        setPinOutput_writeHigh(row_selector[i]);
    }
}

void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    if (!select_row(current_row)) { // Select row
        return;                     // skip NO_PIN row
    }
    matrix_output_select_delay();

    // For each col...
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++, row_shifter <<= 1) {
        uint8_t pin_state = readMatrixPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : row_shifter;
    }

    // Unselect row
    unselect_row();
    matrix_output_unselect_delay(current_row, current_row_value != 0); // wait for all Col signals to go HIGH

    // Update the matrix
    current_matrix[current_row] = current_row_value;
}

void matrix_init(void) {
    // TODO: initialize hardware and global matrix state here
    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }

    for (uint8_t i = 0; i < MATRIX_COLS; i++){
        //initialise column pins as input, DO NOT USE without external pullup resistors
		setPinInput(col_pins[i]);
    }

    // Clear the row selector to INVALID
    unselect_row();

    // Unless hardware debouncing - Init the configured debounce routine
    debounce_init(MATRIX_ROWS);
}

uint8_t matrix_scan(void) {
    matrix_row_t curr_matrix[MATRIX_ROWS] = {0};

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_read_cols_on_row(curr_matrix, current_row);
    }

    bool changed = memcmp(raw_matrix, curr_matrix, sizeof(curr_matrix)) != 0;
    if (changed) {
        memcpy(raw_matrix, curr_matrix, sizeof(curr_matrix));
    }

    // Unless hardware debouncing - use the configured debounce routine
    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    return (uint8_t) changed;
}
