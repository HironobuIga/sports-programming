import Foundation

class SegmentTree<T> {
    var array: [T] = .init()
    var operation: ((T, T) -> T)
    private let initialValue: T
    private let num: Int
    private let length: Int
    
    init(
        initialArray: [T],
        operation: @escaping (T, T) -> T,
        initialValue: T
    ) {
        self.operation = operation
        self.initialValue = initialValue
        self.num = initialArray.count
        let seed = String(num-1, radix: 2).count
        self.length = Int(pow(Double(2), Double(seed)))
        self.array = Array(repeating: initialValue, count: length)
        + initialArray + Array(repeating: initialValue, count: length - num)
        
        for index in (1...length-1).reversed() {
            array[index] = operation(array[2 * index], array[2 * index + 1])
        }
    }
    
    func set(value: T, at index: Int) {
        var newIndex = index + length
        array[newIndex] = value
        newIndex /= 2
        while newIndex > 0 {
            array[newIndex] = operation(
                array[2 * newIndex],
                array[2 * newIndex + 1]
            )
            newIndex /= 2
        }
    }
    
    // get sum of [i, j)
    func get(from fromIndex: Int, to toIndex: Int) -> T {
        var newFromIndex = fromIndex + length
        var newToIndex = toIndex + length
        var left = initialValue
        var right = initialValue
        
        while newToIndex - newFromIndex > 0 {
            if newFromIndex % 2 == 1 {
                left = operation(left, array[newFromIndex])
                newFromIndex += 1
            }
            if newToIndex % 2 == 1 {
                right = operation(array[newToIndex-1], right)
                newToIndex -= 1
            }
            newFromIndex /= 2
            newToIndex /= 2
        }
        return operation(left, right)
    }
}
