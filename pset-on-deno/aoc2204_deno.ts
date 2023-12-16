const day = 4

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

    const lines = infile.split('\n').map((bloc) => {
        return bloc
    })
    lines.pop()
    const len = lines.length
    console.log(lines, len)
    let res1 = 0
    let res2 = 0
    for (const line of lines) {
        const [L, R] = line.split(',')
        const [l, r] = L.split('-').map((n) => Number(n))
        const [ll, rr] = R.split('-').map((n) => Number(n))
        if ((l <= ll && r >= rr ) || (ll <= l && rr >= r))
            res1++
        if (r >= ll && l <= rr)
            res2++
    }
    console.log('part 1:', res1)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

