const day = 1

import { config } from "https://deno.land/x/dotenv/mod.ts"

config()
const session = Deno.env.get("AOC_SESSION")

const fetch_input = (day: number): Promise<string> => {

    const url = `https://adventofcode.com/2022/day/${day}/input`
    const headers = new Headers({ 'Cookie': `session=${session}` })

    return fetch(url, { headers })
        .then ((resp) => resp.text())
        .catch ((err) => { throw err })
}

fetch_input(day).then((infile) => {

    const lines = infile.split('\n\n').map((bloc) => {
        return bloc.split('\n').map(Number)
    })
    const sums = lines.map((bloc) => {
        return bloc.reduce((a, c) => a + c, 0)
    })
    console.log('part 1:', Math.max(...sums))
    sums.sort((a, b) => b - a)
    const top3 = sums[0] + sums[1] + sums[2]
    console.log('part 2:', top3)

}).catch((err) => { throw err })
