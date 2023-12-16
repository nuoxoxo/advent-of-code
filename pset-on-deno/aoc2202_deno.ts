const day = 2

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
    let res = 0
    let res2 = 0
    const dict: Record<string, number> = {
        'A': 1, 'B': 2, 'C': 3,
        'X': 1, 'Y': 2, 'Z': 3,
    }
    for (const line of lines) {
        let [ll , rr] = line.split(' ')
        let [l, r] = [ dict[ll], dict[rr] ]
        if (l == r) {
            res += r + 3
        } else {
            res += r
            rr = l + 1
            if (rr > 3)
                rr = 1
            if (rr == r)
                res += 6
        }

        // part 2
        if (r == 2) {
            res2 += l + 3
        } else if (r == 1) {
            l -= 1
            if (l < 1)
                l = 3
            res2 += l
        } else {
            l += 1
            if (l > 3) {
                l = 1
            }
            res2 += l + 6
        }
    }
    console.log('part 1:', res)
    console.log('part 2:', res2)

}).catch((err) => { throw err })

