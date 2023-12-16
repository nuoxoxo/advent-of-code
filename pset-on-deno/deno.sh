#!/bin/zsh

if [ $1 -ge 0 ] && [ $1 -lt 10 ]; then
    filename="aoc220$1_deno.ts"
elif [ $1 -ge 10 ] && [ $1 -lt 100 ]; then
    filename="aoc22$1_deno.ts"
else
    echo "arg no good"
    exit 1
fi

deno run --allow-read --allow-env --allow-net $filename

