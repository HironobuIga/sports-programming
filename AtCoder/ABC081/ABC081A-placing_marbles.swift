let string = readLine()!
let chars = string.characters
let ans = chars.filter{$0=="1"}.count
print("\(ans)")