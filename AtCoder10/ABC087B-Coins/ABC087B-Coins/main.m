//
//  main.m
//  ABC087B-Coins
//
//  Created by HironobuIga on 2018/10/28.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileHandle *inputFileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSInteger A = [[[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding] integerValue];
        NSInteger B = [[[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding] integerValue];
        NSInteger C = [[[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding] integerValue];
        NSInteger X = [[[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding] integerValue];

        NSInteger count = 0;
        
        for (NSInteger firstCount = 0; firstCount <= A; firstCount++) {
            for (NSInteger secondCount = 0; secondCount <= B; secondCount++) {
                NSInteger leftMoney = X - 500 * firstCount - 100 *secondCount;
                if (leftMoney >= 0 && leftMoney % 50 == 0 && leftMoney / 50 <= C) {
                    count += 1;
                }
            }
        }
        
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString = [NSString stringWithFormat:@"%ld", (long)count];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
