let day = 9
import { config } from "https://deno.land/x/dotenv/mod.ts"
config()
let session = Deno.env.get("AOC_SESSION")

let get_stuff = (day): Promise<string> => {
    let url: string = `https://adventofcode.com/2023/day/${day}/input`
    // console.log(session)
    let headers = new Headers({ 'Cookie': `session=${session}` })
    return fetch(url, { headers })
        .then((resp) => resp.text())
        .catch((err) => { throw err })
}

get_stuff(day).then((infile) => {

    let lines: string[] = infile.split('\n')
    lines.pop()
    let r1 = 0, r2 = 0
    for (let line of lines) {
        let a: number[][] = [line.split(' ').map(Number)]
        a = expl(a)
        for (let aa of a) {
            r1 += aa[aa.length - 1]
        }
        let tmp = 0
        for (let aa of a.reverse()) {
            tmp = aa[0] - tmp
        }
        r2 += tmp
    }
    console.log("part 1:", r1)
    console.log("part 2:", r2)

}).catch((err) => {throw err})

function expl(a: number[][]): number[][] {
    while (a[a.length-1][0] != 0 || new Set(a[a.length-1]).size != 1) {
        let temp: number[] = []
        let i = 0
        while (++i < a[a.length - 1].length) {
            temp.push(a[a.length - 1][i] - a[a.length - 1][i - 1])
        }
        a.push(temp)
    }
    return a
}
