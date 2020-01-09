//
//  main.m
//  ABC088B-CardGameForTwo
//
//  Created by HironobuIga on 2018/10/28.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileHandle *inputFileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSString *firstInputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSInteger N = [firstInputString integerValue];
        NSString *secondInputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSArray *aArray = [secondInputString componentsSeparatedByString:@" "];
        
        // 昇順にソート
        NSArray<NSString *> *sortedArray = [aArray sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
            return [obj1 integerValue] < [obj2 integerValue];
        }];
        
        __block NSInteger alice = 0;
        __block NSInteger bob = 0;
        
        [sortedArray enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if (idx % 2 == 0) {
                alice += [obj integerValue];
            } else {
                bob += [obj integerValue];
            }
        }];
        
        NSInteger answer = alice - bob;
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString = [NSString stringWithFormat:@"%ld", (long)answer];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
