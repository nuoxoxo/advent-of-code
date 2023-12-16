const day = 1

import * as dotenv from 'dotenv'
import axios from 'axios'

dotenv.config()
const session = process.env.AOC_SESSION

const fetch_input = async (day: number) : Promise<string> => {

    const url = `https://adventofcode.com/2022/day/${day}/input`
    const headers = { 'Cookie': `session=${session}` }
    try {
        return await axios.get(url, { headers })
    } catch (err) { throw err }
}

fetch_input(day).then( (infile) => {

    const lines = infile['data'].split('\n\n').map((bloc) => {
        return bloc.split('\n').map(Number)
    })
    const sums = lines.map((bloc) => {
        return bloc.reduce((a, c) => a + c, 0)
    })
    console.log('part 1:', Math.max(...sums))
    sums.sort((a, b) => b - a)
    const top3 = sums.slice(0, 3).reduce((a, c) => a + c, 0)
    console.log('part 2:', top3)

}).catch ((err) => { throw err })
