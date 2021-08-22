import Foundation
let firstLineElements = readLine()!.split(separator: " ")
let h = Int(firstLineElements[0])!
let w = Int(firstLineElements[1])!
var nums = Array<Array<Int>>()
nums.reserveCapacity(h * w)

precondition(h >= 2 && h <= 2_000)
precondition(w >= 2 && w <= 2_000)

for _ in 0..<h {
    for _ in 0..<w {
        let elements = readLine()!.split(separator: " ").map { Int($0)! }
        nums.append(elements)
    }
}

var rows = [Int](repeating: 0, count: h)
var columns = [Int](repeating: 0, count: w)

for i in 0..<h {
    for j in 0..<w {
        rows[i] += nums[i][j]
        columns[j] += nums[i][j]
    }
}

var ans: Array<Array<Int>> = .init()
ans.reserveCapacity(h * w)

for i in 0..<h {
    var row = ""
    for j in 0..<w {
        let element = rows[i] + columns[j] - nums[i][j]
        row.append(String(element) + (j < w - 1 ? " " : ""))
    }
    print(row)
}
