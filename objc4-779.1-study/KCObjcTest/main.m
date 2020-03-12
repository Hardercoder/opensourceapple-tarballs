//
//  main.m
//  studyobjc4
//
//  Created by apple on 2020/3/10.
//

#import <Foundation/Foundation.h>
//#import "MyExpriceObj.h"
//#import "TestObj.h"
//#import "NSObject+DLIntrospection.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        [MyExpriceObj saocaozuo];
        NSObject *obj = [[NSObject alloc] init];
        NSLog(@"为啥打不上断点呢 %@", obj);
//        NSLog(@"classes obj %@", [TestObj classes]);
//        NSLog(@"properties obj %@", [TestObj properties]);
//        NSLog(@"instanceVariables obj %@", [TestObj instanceVariables]);
//        NSLog(@"classMethods obj %@", [TestObj classMethods]);
//        NSLog(@"instanceMethods obj %@", [TestObj instanceMethods]);
//        NSLog(@"parentClassHierarchy obj %@", [TestObj parentClassHierarchy]);
        
        
//        NSLog(@"classes obj1 %@", [TestObj1 classes]);
//        NSLog(@"properties obj1 %@", [TestObj1 properties]);
//        NSLog(@"instanceVariables obj1 %@", [TestObj1 instanceVariables]);
//        NSLog(@"classMethods obj1 %@", [TestObj1 classMethods]);
//        NSLog(@"instanceMethods obj1 %@", [TestObj1 instanceMethods]);
//        NSLog(@"parentClassHierarchy obj1 %@", [TestObj1 parentClassHierarchy]);
        
        NSDate *stopDate = [[[NSDate alloc] init] dateByAddingTimeInterval:30.f];
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:stopDate];
    }
    return 0;
}
