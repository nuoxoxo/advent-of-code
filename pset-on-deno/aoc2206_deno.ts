const day = 6

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
    const s = lines[0]
    const n = s.length
    console.log(s, n)

    let [res1, res2] = [-1, -1]
    let i = -1
    while (++i < n - 4) {
        const l: string = s.slice(i, i + 4)
        const S = new Set(l)
        console.log(S)
        if (S.size === 4) {
            res1 = i + 4
            break
        }
    }
    const p2 = 14
    i = -1
    while (++i < n - p2) {
        const l: string = s.slice(i, i + p2)
        const S = new Set(l)
        if (S.size === p2) {
            res2 = i + p2
            break
        }
    }
    console.log('part 1:', res1)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

