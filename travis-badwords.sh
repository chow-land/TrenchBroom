#!/bin/bash

BAD_WORDS="fixup dropme wip"

LOG_ARGS=""
for BAD_WORD in $BAD_WORDS
do
	LOG_ARGS="$LOG_ARGS --grep=$BAD_WORD"
done

BAD_COMMITS=$(git log $(git rev-parse --abbrev-ref HEAD) --oneline --not origin/master $LOG_ARGS -i)

if [ "$BAD_COMMITS" ] ; then
    echo "Found bad words in branch history!"
    echo "Bad word list: $BAD_WORDS"
    echo
    echo "Bad commits:"
    echo "$BAD_COMMITS"

    exit 1
fi

exit 0