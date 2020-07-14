#!/bin/bash

BAD_WORDS="fixup dropme wip"

LOG_ARGS=""
for BAD_WORD in $BAD_WORDS
do
	LOG_ARGS="$LOG_ARGS --grep=$BAD_WORD"
done

GIT_COMMAND="git log $(git rev-parse --abbrev-ref HEAD) --oneline --not origin/master $LOG_ARGS -i"

git fetch origin master
echo "$GIT_COMMAND"
BAD_COMMITS=$(eval "$GIT_COMMAND")

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