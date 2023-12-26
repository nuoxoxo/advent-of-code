#!/bin/zsh

if [ $1 -ge 0 ] && [ $1 -lt 10 ]; then
    filename="aoc150$1.py"
    inputname="0$1.0"
    testname="0$1.1"
elif [ $1 -ge 10 ] && [ $1 -lt 100 ]; then
    filename="aoc15$1.py"
    inputname="$1.0"
    testname="$1.1"
else
    echo "arg no good"
    exit 1
fi

python3 $filename < $inputname
#python3 $filename < $testname

