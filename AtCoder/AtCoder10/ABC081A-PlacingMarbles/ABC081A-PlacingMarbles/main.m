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
        
        NSInteger count = 0;
        for (NSInteger index = 0; index < inputString.length; index++) {
            if ([inputString characterAtIndex:index] == '1') {
                count += 1;
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
