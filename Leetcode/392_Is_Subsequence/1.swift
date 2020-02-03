class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        guard s.isEmpty == false else { return true }
        var iterator = s.makeIterator()
        var currentChar: Character? = iterator.next()
        
        for char in t {
            if char == currentChar {
                currentChar = iterator.next()
            }
        }
        
        return currentChar == nil
    }
}
