#!/bin/bash

MASTER_FOUND=$(git branch -r --list origin/master)
if [ "$MASTER_FOUND" == "" ] ; then
	echo
	echo "Skipping check for bad words"
	echo

	exit 0
fi

BAD_WORDS="fixup dropme wip"

LOG_ARGS=""
for BAD_WORD in $BAD_WORDS
do
	LOG_ARGS="$LOG_ARGS --grep=$BAD_WORD"
done

GIT_COMMAND="git log --oneline $(git rev-parse --abbrev-ref HEAD) $LOG_ARGS -i --not origin/master"

echo "$GIT_COMMAND"
BAD_COMMITS=$(eval "$GIT_COMMAND") || exit 1

if [ "$BAD_COMMITS" ] ; then
    echo
    echo "Found bad words in branch history!"
    echo "Bad word list: $BAD_WORDS"
    echo
    echo "Bad commits:"
    echo "$BAD_COMMITS"
    echo

    exit 1
fi

exit 0