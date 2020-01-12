class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
        var result = [[Int]]()
        recurse(index: 0, nums: nums, current: [], result: &result)
        return result
    }
    
    func recurse(index: Int, nums: [Int], current: [Int], result: inout [[Int]]) {
        guard index < nums.count else {
            result.append(current)
            return
        }
        
        var current = current
        recurse(index: index + 1, nums: nums, current: current, result: &result)
        current.append(nums[index])
        recurse(index: index + 1, nums: nums, current: current, result: &result)
    }
}