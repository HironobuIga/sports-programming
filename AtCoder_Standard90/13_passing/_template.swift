import Foundation

// Priority Queue
struct PriorityQueue<Element> {
    private var elements: [Element] = []
    private let areInIncreasingOrder: (Element, Element) -> Bool
    
    init<S>(_ elements: S, by areInIncreasingOrder: @escaping (Element, Element) -> Bool) where S: Sequence, S.Element == Element {
        self.areInIncreasingOrder = areInIncreasingOrder
        for element in elements {
            append(element)
        }
    }
    
    init(by areInIncreasingOrder: @escaping (Element, Element) -> Bool) {
        self.init(EmptyCollection(), by: areInIncreasingOrder)
    }
    
    var isEmpty: Bool { elements.isEmpty }
    var count: Int { elements.count }
    var first: Element? { elements.first }
    
    mutating func append(_ element: Element) {
        var i = elements.count
        elements.append(element)
        elements.withUnsafeMutableBufferPointer { elements in
            while i > 0 {
                let parentIndex = (i - 1) >> 1
                let parent = elements[parentIndex]
                guard areInIncreasingOrder(element, parent) else { break }
                elements[parentIndex] = element
                elements[i] = parent
                i = parentIndex
            }
        }
    }
    
    mutating func popFirst() -> Element? {
        guard let element = elements.popLast() else { return nil }
        guard let first = elements.first else { return element }
        
        elements.withUnsafeMutableBufferPointer { elements in
            elements[0] = element
            
            var  i = 0
            while true {
                var childIndex: Int = (i << 1) + 1
                guard childIndex < elements.count else { break }
                var child: Element = elements[childIndex]
                let rightIndex = childIndex + 1
                if rightIndex < elements.count {
                    let right = elements[rightIndex]
                    if areInIncreasingOrder(right, child) {
                        childIndex = rightIndex
                        child = right
                    }
                }
                if areInIncreasingOrder(element, child) { break }
                elements[childIndex] = element
                elements[i] = child
                i = childIndex
            }
        }

        return first
    }
}

extension PriorityQueue where Element: Comparable {
    init<S>(_ elements: S) where S: Sequence, S.Element == Element {
        self.init(elements, by: <)
    }
    
    init() {
        self.init(by: <)
    }
    
}

// Queue
public struct Queue<T> {
  fileprivate var array = [T?]()
  fileprivate var head = 0

  public var isEmpty: Bool {
    return count == 0
  }

  public var count: Int {
    return array.count - head
  }

  public mutating func enqueue(_ element: T) {
    array.append(element)
  }

  public mutating func dequeue() -> T? {
      guard let element = array[head] else { return nil }

    array[head] = nil
    head += 1

    let percentage = Double(head)/Double(array.count)
    if array.count > 50 && percentage > 0.25 {
      array.removeFirst(head)
      head = 0
    }

    return element
  }

  public var front: T? {
    if isEmpty {
      return nil
    } else {
      return array[head]
    }
  }
}

// ======================================================================== //
let nums = readLine()!.split(separator: " ").map { Int($0)! }
let N = nums[0]
let M = nums[1]

 struct Path: Hashable {
    let from: Int
    let to: Int
}

struct AccumulativeCost: Comparable {
    let point: Int
    let cost: Int
    static func < (lhs: AccumulativeCost, rhs: AccumulativeCost) -> Bool {
        lhs.cost < rhs.cost
    }
}

var dict: [Int: [Int]] = [:]
var costs: [Path: Int] = [:]

for _ in 0..<M {
    let props = readLine()!.split(separator: " ").map { Int($0)! }
    let a = props[0]
    let b = props[1]
    let c = props[2]
    
    if (dict[a] == nil) {
        dict[a] = [b]
    } else {
        dict[a]?.append(b)
    }
    
    if (dict[b] == nil) {
        dict[b] = [a]
    } else {
        dict[b]?.append(a)
    }
    
    let pathA = Path(from: a, to: b)
    let pathB = Path(from: b, to: a)
    costs[pathA] = c
    costs[pathB] = c
}

func dicstra(dict: [Int: [Int]], costs: [Path: Int], start: Int, goal: Int) -> [Int] {
    var d = Array(repeating: 2<<31, count: N + 1)
    d[start] = 0
    var priorityQueue = PriorityQueue<AccumulativeCost>(by: <)
    priorityQueue.append(AccumulativeCost(point: start, cost: 0))
    while priorityQueue.count > 0 {
        let accumulativeConst = priorityQueue.popFirst()!
        let cost = accumulativeConst.cost
        let point = accumulativeConst.point
        if d[point] < cost {
            continue
        }
        for nv in dict[point] ?? [] {
            let path = Path(from: point, to: nv)
            if cost + costs[path]! < d[nv] {
                d[nv] = cost + costs[path]!
                priorityQueue.append(AccumulativeCost(point: nv, cost: d[nv]))
            }
        }
    }
    return d
}

let startToGoal = dicstra(dict: dict, costs: costs, start: 1, goal: N)
let goalToVia = dicstra(dict: dict, costs: costs, start: N, goal: 1)
for via in 1...N {
    let prev = startToGoal[via]
    let post = goalToVia[via]
    print(prev + post)
}
