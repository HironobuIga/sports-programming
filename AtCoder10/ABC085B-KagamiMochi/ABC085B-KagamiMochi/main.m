//
//  main.m
//  ABC085B-KagamiMochi
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
        
        NSMutableArray<NSString *> *dArray = [[NSMutableArray alloc] init];
        for (NSInteger index = 0; index < N; index++) {
            NSString *inputString = [[NSString alloc] initWithData:[inputFileHandle availableData] encoding:NSUTF8StringEncoding];
            [dArray addObject:inputString];
        }
        
        NSArray *sortedArray = [dArray sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
            return [obj1 integerValue] < [obj2 integerValue];
        }];
        NSArray *distinctSortedArray = [[[NSSet alloc] initWithArray:sortedArray] allObjects];
        
        NSInteger answer = distinctSortedArray.count;
        NSFileHandle *outputFileHandle = [NSFileHandle fileHandleWithStandardOutput];
        NSString *outputString = [NSString stringWithFormat:@"%ld", (long)answer];
        [outputFileHandle writeData:[outputString dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle writeData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
        [outputFileHandle closeFile];
    }
    return 0;
}
