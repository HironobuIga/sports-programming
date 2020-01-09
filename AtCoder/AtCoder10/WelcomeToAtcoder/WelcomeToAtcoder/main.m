//
//  main.m
//  WelcomeToAtcoder
//
//  Created by HironobuIga on 2018/10/27.
//  Copyright © 2018年 iganin. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // 標準入力の取得
        NSFileHandle *fileHandle = [NSFileHandle fileHandleWithStandardInput];
        NSData *firstData = [fileHandle availableData];
        NSInteger a = [[[NSString alloc] initWithData:firstData encoding:NSUTF8StringEncoding] integerValue];
        NSData *secondData = [fileHandle availableData];
        NSArray<NSString *> *secondDataArray = [[[NSString alloc] initWithData:secondData encoding:NSUTF8StringEncoding] componentsSeparatedByString:@" "];
        NSInteger b, c;
        b = [secondDataArray[0] integerValue];
        c = [secondDataArray[1] integerValue];
        NSString *s = [[NSString alloc] initWithData:[fileHandle availableData] encoding:NSUTF8StringEncoding];
        
        // 問題を解く
        NSInteger ans = a + b + c;
        NSString *stdoutString = [NSString stringWithFormat:@"%ld %@", (long)ans, s];
        
        // 標準出力の実行
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        [outputFileHandle writeData:[stdoutString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
