

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

func gcd(_ a: Int,_ b: Int) -> Int {
    if b == 0 {return a}
    else { return gcd( b, a % b ) }
}
 


func readStringArray() -> [String] {
    return readLine()!.split(separator: " ").map {String($0) }
}
 
func readIntArray() -> [Int] {
    return readLine()!.split(separator: " ").map{ Int(String($0))! }
}
 
func readInt() -> Int {
    return Int(readLine()!)!
}
 
func read2Ints() -> (a: Int, b: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0], b: ints[1])
}
 
func read3Ints() -> (a: Int, b: Int, c: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0], b: ints[1], c: ints[2])
}

func read4Ints() -> (a: Int, b: Int, c: Int, d: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0], b: ints[1], c: ints[2], d:ints[3])
}

func readIntArrayMinus1() -> [Int] {
    return readLine()!.split(separator: " ").map{ Int(String($0))! - 1}}
 
func readIntMinus1() -> Int {
    return Int(readLine()!)! - 1
}
 
func read2IntsMinus1() -> (a: Int, b: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0]-1, b: ints[1]-1)
}
 
func read3IntsMinus1() -> (a: Int, b: Int, c: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0]-1, b: ints[1]-1, c: ints[2]-1)
}

func read4IntsMinus1() -> (a: Int, b: Int, c: Int, d: Int) {
    let ints = readLine()!.split(separator: " ").map{ Int(String($0))!}
    return (a: ints[0]-1, b: ints[1]-1, c: ints[2]-1, d:ints[3]-1)
}

