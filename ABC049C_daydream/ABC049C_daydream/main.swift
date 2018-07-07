//
//  main.swift
//  ABC049C_daydream
//
//  created on 2018/07/07.
//  Copyright © 2018年. All rights reserved.
//

import CoreFoundation

func reversedArray<T>(a: [T]) -> [T] {
    return a.reverse()
}

let criterias = ["dream", "dreamer", "erase", "eraser"].map{ Array($0.characters.reverse()) }
let str = Array(readLine()!.characters.reverse())
var count = 0

while count < str.count {
    var matched: [Character]?
    for criteria in criterias {
        let criteriaLength = criteria.count
        let leftLength = str.count - count
        
        if criteriaLength <= leftLength {
            var index = 0
            while index < criteriaLength {
                if str[count + index] != criteria[index] { break }
                index = index + 1
            }
            
            if index == criteriaLength {
                matched = criteria
                break
            }
        }
    }
    
    if matched == nil {
        print("NO")
        exit(0)
    }
    
    count = count + matched!.count
}

print("YES")
