//
//  main.m
//  studyobjc4
//
//  Created by apple on 2020/3/10.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSObject *myObj = [[NSObject alloc] init];
        
        NSLog(@"instanceSize %ld  mallocSize %ld",class_getInstanceSize([myObj class]), malloc_size((__bridge void *)myObj));
        
        NSDate *dateAfter3Seconds = [[[NSDate alloc] init] dateByAddingTimeInterval:7];
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:dateAfter3Seconds];
        
    }
    return 0;
}
