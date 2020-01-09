//
//  main.m
//  ABC085C-Otoshidama
//
//  Created by HironobuIga on 2018/10/29.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileHandle *inputFileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSString *inputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
        NSArray<NSString *> *inputArray = [inputString componentsSeparatedByString:@" "];
        NSInteger N = [inputArray[0] integerValue];
        NSInteger Y = [inputArray[1] integerValue];
        NSMutableArray *answerArray = [@[@"-1", @"-1", @"-1"] mutableCopy];
        
        for (NSInteger a = 0; a < N; a++) {
            for (NSInteger b = 0; b < N - a; b++) {
                NSInteger c = N - a - b;
                if ((a * 10000 + b * 5000 + c * 1000) == Y) {
                    answerArray[0] = [NSString stringWithFormat:@"%ld", (long)a];
                    answerArray[1] = [NSString stringWithFormat:@"%ld", (long)b];
                    answerArray[2] = [NSString stringWithFormat:@"%ld", (long)c];
                }
            }
        }
        
        NSString *outputString = [answerArray componentsJoinedByString:@" "];
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
