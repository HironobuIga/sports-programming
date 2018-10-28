//
//  main.m
//  ABC081A-PlacingMarbles
//
//  Created by HironobuIga on 2018/10/28.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileHandle *inputFileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSString *inputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSInteger N = [inputString integerValue];
        NSString *secondString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSArray *numberStringArray = [secondString componentsSeparatedByString:@" "];
        
        NSInteger count = 0;
        NSMutableArray<NSNumber *> *numberArray = [@[] mutableCopy];
        NSArray<NSNumber *> *devidedNumberArray = [numberStringArray copy];
        
        while (true) {
            BOOL isExistOdd = false;
            for(NSNumber *number in devidedNumberArray) {
                if ([number integerValue] % 2 == 1) {
                    isExistOdd = true;
                    break;
                }
            }
            if (isExistOdd) {
                break;
            }
            for(NSNumber *number in devidedNumberArray) {
                NSInteger devided = [number integerValue] / 2;
                [numberArray addObject:[NSNumber numberWithInteger:devided]];
            }
            devidedNumberArray = [numberArray copy];
            count += 1;
        }
        
        
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString = [NSString stringWithFormat:@"%ld", (long)count];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
