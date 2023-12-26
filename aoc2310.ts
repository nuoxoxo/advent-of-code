let day = 10
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

  let lines: string[] = infile.split('\n')
  lines.pop()
  // console.log(lines[0])


  // Solver

  let part1 = 0, part2 = 0

  let starting_points: number[][] = []
  let R = lines.length, C = lines[0].length
  let r = -1, c

  while (++r < R) {

    if ( lines[r].includes('S') ) {
      c = -1
      while (++c < C) {
        if (lines[r][c] == 'S')
          starting_points.push([r, c])
      }
    }
  }
  if (starting_points.length !== 1) { throw new Error('wtf') }

  let Start:number[] = starting_points.pop()
  let Go: string[] = [ 'J|L', '7|F', 'J-7', 'L-F'] // order : UDLR
  let Get:string[] = [Go[1], Go[0], Go[3], Go[2]]
  let Deque: number[][] = [ Start ]

  let Seen: Set<number[]> = new Set()
  Seen.add(Start)
  // let Seen: Set<string> = new Set()
  // Seen.add(`${Start[0]},${Start[1]}`)
  // console.log('From:', Start)
  // console.log('Seen:', Seen)
  // console.log('BFS :', Deque)

  let dr = [-1, 1, 0, 0]
  let dc = [ 0, 0,-1, 1] // UDLR

  // Find what S is for part 2
  let SS: Set<string> = new Set(['-', '|', '7', 'F', 'L', 'J'])

  while (Deque.length > 0) {

    let rc: number[] | undefined = Deque.shift()
    if (rc === undefined) return
    let [r, c] = rc
    // console.log([r, c]) /// DBG
    let curr_pipe = lines[r][c]
    let i = -1
    while (++i < 4) {

      let rr = r + dr[i]
      let cc = c + dc[i]
      // console.log(checkSetHas(Seen, [rr,cc])) /// DBG
      if (checkSetHas(Seen, [rr,cc]) || ! (rr > -1 && rr < R && cc > -1 && cc < C))
        continue
      let next_pipe = lines[rr][cc]
      if ((Go[i]+'S').includes(curr_pipe) && Get[i].includes(next_pipe)) {
        Seen.add( [ rr,cc ])
        Deque.push([rr,cc ])
        // console.log('curr:', str, curr_pipe, 'next:', Get[i], next_pipe) /// DBG
        if (curr_pipe == 'S') {
          SS = new Set([...SS].filter(char => new Set((Go[i] + 'S').split('')).has(char)))
        }
      }
    }
  }

  part1 = Math.floor(Seen.size / 2)

  //////////////////////////////////////////////////
  //                   part 2                    //
  //////////////////////////////////////////////////

  r = -1
  while (++r < R) {
    c = -1
    while (++c < C) {
      if (!checkSetHas(Seen, [r,c]))
        lines[r] = lines[r].slice(0, c) + '.' + lines[r].slice(c + 1);
    }
  }
  // console.log(lines)
  let OUT: Set<number[]> = new Set([])
  r = -1
  while (++r < R) {

    let inside = false
    let upward = false // is this strict true?
    c = -1

    while (++c < C) {

      let curr_pipe = lines[r][c]
      if (curr_pipe == 'S')
        [curr_pipe] = SS
      if (curr_pipe == '|') {
        inside = !inside
      } else if (curr_pipe == 'L') {
        upward = true
      } else if (curr_pipe == 'F') {
        upward = false
      } else if (upward && curr_pipe == '7') {
        inside = ! inside
      } else if (!upward && curr_pipe == 'J') {
        inside = ! inside
      }
      if ( ! inside) {
        OUT.add([r, c])
      }
    }
  }

  let UNION: Set<number[]> = new Set([...OUT])

  for (let point of Seen) {

    if (!checkSetHas(UNION, point)) {
      UNION.add(point)
    }
  }

  let DIFFERENCE: Set<number[]> = new Set()
  r = -1

  while (++r < R) {

    c = -1
    while (++c < C) {
      if (!checkSetHas(UNION, [r,c])) {
        DIFFERENCE.add([r,c])
      }
    }
  }

  part2 = R * C - UNION.size

  console.log("part 1:", part1)
  console.log("part 2:", part2)

}).catch((err) => { throw err })

const checkTwoArraysAreEqual = (L:number[], R:number[]): boolean =>
{ return L.length === R.length && L.every((val, idx) => val === R[idx]) }

const checkSetHas = (set: Set<number[]>, this_array: number[]): boolean =>
{
  for (let that_array of set)
    if (checkTwoArraysAreEqual(this_array, that_array))
      return true
  return false
}

