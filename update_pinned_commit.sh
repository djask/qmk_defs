#!/bin/bash

if [[ $# -gt 1 ]]; then
    echo "Usage: $0"
    echo "Script will try and update the pinned commits of all projects in the repo"
    exit 1
fi

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
GIT_REV=`cd $SCRIPT_DIR/.. && git rev-parse HEAD`

try_update_kb_pinned_commit() {
    TARGET_DIR="$SCRIPT_DIR/$1"

    cd $TARGET_DIR;
    qmk compile -km default
    ret=$?
    echo "Return code is: $ret"
    if [[ $ret -ne 0 ]]; then
        echo "Bad return on qmk compile, cannot update pinned commit hash"
        return 2
    fi

    echo $GIT_REV > "$TARGET_DIR/_pinned_commit.txt"
}

if [[ $# -eq 0 ]]; then
    find -maxdepth 1 -type d ! -name ".*" | while read proj; do
        try_update_kb_pinned_commit `basename $proj`
    done
else
    TARGET_DIR=$1
    if [[ ! -d $SCRIPT_DIR/$TARGET_DIR ]]; then
        echo "$TARGET_DIR does not exist in the repo"
        exit 1
    fi
    try_update_kb_pinned_commit $TARGET_DIR
fi
