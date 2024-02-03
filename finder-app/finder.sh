#!/bin/sh

if [ $# -lt 2 ]; then
	echo "Not enough arguments"
	exit 1
fi

if [ ! -d ${1} ]; then
	echo "Provided directory doesn't exist"
	exit 1
fi

FILES=$(find ${1} -type f | wc -l)
LINES=$(grep -r "${2}" ${1} | wc -l)

echo "The number of files are ${FILES} and the number of matching lines are ${LINES}"

exit 0
