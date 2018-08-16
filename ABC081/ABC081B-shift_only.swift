// インプットの処理
let count = Int(readLine()!)!
let numbers = readLine()!.characters.split{$0==" "}.map{Int(String($0))!}

var mutableNumbers = numbers
var tryCount: Int = 0

while true {
    // 偶数でfilter filter後の値を 1/2倍する
    mutableNumbers = mutableNumbers.filter{($0 % 2) == 0}.map{$0 / 2}
        if mutableNumbers.count != numbers.count {
            // filterで数がければ（2の倍数がなくなれば）break
            break
        }
    tryCount = tryCount + 1
}
print("\(tryCount)")