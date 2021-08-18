import Foundation

let inputs = readLine()!.split(separator: " ")
let N = Int(inputs[0])!
let L = Int(inputs[1])!
let K = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map { Int($0)! }

func canSolve(m: Int) -> Bool {
    var count = 0;
    var preLength = 0;
    
    for index in 0..<N {
        if A[index] - preLength >= m && L - A[index] >= m {
            count += 1
            preLength = A[index]
        }
    }
    
    return count >= K
}

var left = 0
var right = L

while right - left > 1 {
    let middle = (left + right) / 2
    let solve = canSolve(m: middle)
    switch solve {
    case true: left = middle
    case false: right = middle
    }
}

print(left)
