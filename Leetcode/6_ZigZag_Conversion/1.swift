 class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        guard s.count > 1 else { return s }
        guard numRows > 1 else { return s }
        
        // making numRows boxes
        var rows = [String](repeating: "", count: numRows)
        let threshold = (numRows - 1) * 2
        
        for (index, char) in s.enumerated() {
            let location = index % threshold
            if location < numRows {
                rows[location].append(char)
            } else {
                let upLocation = location - numRows
                rows[numRows-1-upLocation-1].append(char)
            }
        }
        
        let answer = rows.flatMap { $0 }
        return String(answer)
    }
}

let solution = Solution()
let ans = solution.convert("A", 1)
print(ans)
