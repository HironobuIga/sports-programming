  class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
        var result = [String]()
        backTrack(result: &result, cur: "", open: 0, close: 0, max: n)
        return result
    }
    
    func backTrack(result: inout [String], cur: String, open: Int, close: Int, max: Int) {
        if cur.count == max * 2 {
            result.append(cur)
            return
        }
        
        if open < max {
            backTrack(result: &result, cur: cur + "(", open: open + 1, close: close, max: max)
        }
        if close < open {
            backTrack(result: &result, cur: cur + ")", open: open, close: close + 1, max: max)
        }
    }
}