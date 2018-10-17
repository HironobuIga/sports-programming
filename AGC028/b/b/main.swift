//
//  main.swift
//  b
//
//  Created by HironobuIga on 2018/10/13.
//  Copyright © 2018年 iganin. All rights reserved.
//

import Foundation

var answer: Int = 0
var caches = [[Int]: Int]()

func calculate(inputDatas: [Int]) -> Int {
    var ret: Int = 0
    if let cache = caches[inputDatas] {
        return cache
    }
    for num in inputDatas {
        ret += num
    }
    if inputDatas.count  == 1 {
        return ret
        
    }
    
    for (index, _) in inputDatas.enumerated() {
        if index == 0 {
            ret += calculate(inputDatas: Array(inputDatas.dropFirst()))
        } else if index == inputDatas.count - 1 {
            ret += calculate(inputDatas: Array(inputDatas.dropLast()))
        } else {
            ret += calculate(inputDatas: Array(inputDatas[0..<index]))
            ret += calculate(inputDatas: Array(inputDatas[index+1..<inputDatas.count]))
        }
    }
    caches[inputDatas] = ret
    return ret
}

let N = Int(readLine()!)
let A: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }

print(calculate(inputDatas: A))
