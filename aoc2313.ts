let day = 13
import { config } from "https://deno.land/x/dotenv/mod.ts"
config()
let session = Deno.env.get("AOC_SESSION")

let get_stuff = (day): Promise<string> => {

  let url: string = `https://adventofcode.com/2023/day/${day}/input`
  console.log(session)
  let headers = new Headers({ 'Cookie': `session=${session}` })
  return fetch(url, { headers })
        .then((resp) => resp.text())
        .catch((err) => { throw err })
}

get_stuff(day).then((infile) => {

  let raw: string[] = infile.split('\n')
  raw.pop()

  let lines:string[][][] = []
  let temp:string[][] = []
  for (let line of raw) {

    if ( line.length === 0 ) {
      lines.push( temp )
      temp = []
    } else {
      temp.push( Array.from( line ) )
    }
  }
  // get the last left-alone block
  if (temp.length) {
    lines.push( temp )
  }


  let [part1, part2] = [0, 0]

  //console.log(lines)

  // Solver

  let coordinates: number[][] = []
  let p2 = true
  let lhs, rhs, axis
  let i = -1

  while (++i < lines.length) {

    // for (const bloc of lines) {

    // transpose it yea !
    // ++nth_bloc
    let bloc: string[][] = lines[i]
    let tp: string[][] = bloc[0].map((_, col) => bloc.map((row) => row[col]))

    lhs = horver_calculator(bloc)
    rhs = horver_calculator(tp)
    part1 += lhs * 100 + rhs

    axis = lhs !== 0 ? 1 : 2
    coordinates.push([1, i, axis, lhs + rhs])

    lhs = horver_calculator(bloc, p2)
    rhs = horver_calculator(tp, p2)
    part2 += lhs * 100 + rhs

    axis = lhs !== 0 ? 1 : 2
    coordinates.push([2, i, axis, lhs + rhs])
  }

  console.log("part 1:", part1)
  console.log("part 2:", part2)

}).catch((err) => { throw err })

const horver_calculator = (bloc: string[][], part2 = false): number => {

  let index = 0
  let i = 0
  while (++i < bloc.length) {
    let diff = 0,
      u = i - 1,
      d = i
    let busted = false
    while (u > -1 && d < bloc.length) {
      let j = -1
      while (++j < bloc[0].length) {
        if (bloc[u][j] != bloc[d][j]) {
          diff += 1
        }
        if (diff > 1) {
          busted = true
          break
        }
      }
      if (busted) {
        break
      }
      u -= 1
      d += 1
    }
    if ((!part2 && diff == 0) || (part2 && diff == 1)) {
      index = i
      break
    }
  }
  return index
}

