#!/bin/bash

if [ $1 -ge 0 ] && [ $1 -lt 10 ]; then
    filename="aoc220$1.ts"
elif [ $1 -ge 10 ] && [ $1 -lt 100 ]; then
    filename="aoc22$1.ts"
else
    echo "arg no good"
    exit 1
fi

jsname="${filename%.ts}.js"

# npm i @types/node axios dotenv
tsc $filename && node $jsname && rm $jsname
