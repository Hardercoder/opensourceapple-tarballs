//
//  TestObj.h
//  studyobjc4
//
//  Created by apple on 2020/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestObj : NSObject {
    BOOL _testBool;
    NSInteger _testInteger;
    CGFloat _testFloat;
    NSString *_testString;
    NSArray *_testArray;
    NSDictionary *_testDict;
}
@property (nonatomic, assign) BOOL pBool;
@property (nonatomic, assign) NSInteger pInteger;
@property (nonatomic, assign) CGFloat pFloat;

@property (nonatomic, strong) NSString *pString;
@property (nonatomic, strong) NSArray *pArray;
@property (nonatomic, strong) NSDictionary *pDictionary;


- (void)instanceMethod0;
- (void)instanceMethod1:(NSString*)str;

+ (void)classMethod0;
+ (void)classMethod1;

@end

@interface TestObj1 : TestObj {
    BOOL _test1Bool;
    NSInteger _test1Integer;
    CGFloat _test1Float;
    NSString *_test1String;
    NSArray *_test1Array;
    NSDictionary *_test1Dict;
}
@property (nonatomic, assign) BOOL p1Bool;
@property (nonatomic, assign) NSInteger p1Integer;
@property (nonatomic, assign) CGFloat p1Float;

@property (nonatomic, strong) NSString *p1String;
@property (nonatomic, strong) NSArray *p1Array;
@property (nonatomic, strong) NSDictionary *p1Dictionary;

- (void)instance1Method2:(NSString*)str;

+ (void)class1Method2;
@end

NS_ASSUME_NONNULL_END
