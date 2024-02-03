#!/bin/sh

if [ $# -lt 2 ]; then
	echo "Not enough arguments"
	exit 1
fi

FILE=$(basename ${1})
DIR=$(dirname ${1})

mkdir -p ${DIR}
echo "${2}" > ${DIR}/${FILE}

exit 0

