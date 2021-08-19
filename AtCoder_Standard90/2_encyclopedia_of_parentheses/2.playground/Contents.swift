import Foundation

let input = readLine()!
let N = Int(input)!

func judge(s: String) -> Bool {
    var count = 0
    for char in s {
        if char == "(" { count += 1 }
        if char == ")" { count -= 1 }
        if count < 0 { return false }
    }
    return count == 0
}

for i in 0..<(1<<N) {
    var candidate = ""
    for j in 0..<N {
      let k = N - j - 1
      switch i & (1<<k) == 0 {
        case true: candidate.append("(")
        case false: candidate.append(")")
      }
    }
    let result = judge(s: candidate)
    if result == true { print(candidate) }
}
