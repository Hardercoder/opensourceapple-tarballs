//
//  MyExpriceObj.m
//  studyobjc4
//
//  Created by apple on 2020/3/10.
//

#import "MyExpriceObj.h"
#import <objc/runtime.h>
#import <malloc/malloc.h>

@implementation MyExpriceObj
+ (void)studyObjSize {
    NSObject *myObj = [[NSObject alloc] init];
    NSLog(@"instanceSize %ld  mallocSize %ld",class_getInstanceSize([myObj class]), malloc_size((__bridge void *)myObj));
}


@end
