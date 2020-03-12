//
//  TestObj.m
//  studyobjc4
//
//  Created by apple on 2020/3/12.
//

#import "TestObj.h"

@interface TestObj() {
    BOOL _innerBool;
    NSString *_innerString;
}
@end

@implementation TestObj
- (void)instanceMethod0 {
    NSLog(@"%s",__FUNCTION__);
}
- (void)instanceMethod1:(NSString*)str {
    NSLog(@"%s",__FUNCTION__);
}
- (void)instanceInnerMethod2:(NSString*)str {
    NSLog(@"%s",__FUNCTION__);
}

+ (void)classMethod0 {
    NSLog(@"%s",__FUNCTION__);
}
+ (void)classMethod1 {
    NSLog(@"%s",__FUNCTION__);
}

+ (void)classInnerMethod1 {
    NSLog(@"%s",__FUNCTION__);
}

@end

@implementation TestObj1
- (void)instance1Method2:(NSString*)str {
    NSLog(@"%s",__FUNCTION__);
}

+ (void)class1Method2 {
    NSLog(@"%s",__FUNCTION__);
}

@end
