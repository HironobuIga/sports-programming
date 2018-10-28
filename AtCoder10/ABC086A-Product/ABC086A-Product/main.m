//
//  main.m
//  ABC086A-Product
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
        NSInteger a, b;
        a = [inputArray[0] integerValue];
        b = [inputArray[1] integerValue];
        
        NSInteger product = a * b;
        
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString;
        outputString = (product % 2 == 0) ? @"even" : @"odd";
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
