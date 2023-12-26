let day = 2
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

    let D: {[key: string]: number} = {'red': 12, 'green': 13, 'blue': 14}
    let lines: string[] = infile.split('\n')
    lines.pop()
    let r1 = 0
    let r2 = 0
    let idx = 1
    for (let line of lines) {
        line = line.trim()
        let s: string[] = line.split(':')[1].split(' ')
        s.shift()
        let ok = true
        let i = 0
        while (i < s.length - 1) {
            let w = s[i + 1]
            if (w[w.length-1] === ',' || w[w.length-1] === ';')
                w = w.slice(0, -1)
            let v = parseInt(s[i])
            if (D[w] < v)
                ok = false
            i += 2
        }
        if (ok)
            r1 += idx
        // part 2
        let [R, B, G] = [0, 0, 0]
        let rr: string[] = line.split(':')[1].split(';')
        for (let el of rr) {
            let e: string[] = el.split(' ')
            e.shift()
            i = 0
            while (i < e.length - 1) {
                let v = parseInt(e[i])
                let k = e[i + 1]
                if (k.includes('red'))
                    R = Math.max(R, v)
                if (k.includes('blue'))
                    B = Math.max(B, v)
                if (k.includes('green'))
                    G = Math.max(G, v)
                i += 2
            }
        }
        idx++
        r2 += R * B * G
    }
    // console.log(R, G, B, R * G * B, r2)
    console.log("part 1:", r1)
    console.log("part 2:", r2)

}).catch((err) => {throw err})
