//
//  main.m
//  ABC083B-SomeSums
//
//  Created by HironobuIga on 2018/10/28.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileHandle *inputFileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSString *inputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSArray<NSString *> *inputArray = [inputString componentsSeparatedByString:@" "];
        NSInteger N, A, B;
        N = [inputArray[0] integerValue];
        A = [inputArray[1] integerValue];
        B = [inputArray[2] integerValue];
        
        NSInteger sum = 0;
        
        for (NSInteger number = 1; number <= N; number++) {
            NSInteger left = number;
            NSInteger smallSum = 0;
            while (left > 0) {
                smallSum += left % 10;
                left = left / 10;
            }
            if (smallSum >= A && smallSum <= B) {
                sum += number;
            }
        }
        
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString = [NSString stringWithFormat:@"%ld", (long)sum];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
