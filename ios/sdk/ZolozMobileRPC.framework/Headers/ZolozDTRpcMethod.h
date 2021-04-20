//
//  ZolozDTRpcMethod.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZolozDTRpcMethod : NSObject

/** Operation type */
@property(nonatomic, copy) NSString *operationType;

/** 期望返回的对象类型。*/
@property(nonatomic, unsafe_unretained) Class resultClass;
@property(nonatomic, copy) NSString *returnType;
@property(nonatomic, assign) BOOL checkLogin;

/** 如果一个 PRC 方法的返回值是一个集合类型，\code elementClass 指定集合中元素的类型。否则该属性为 nil。*/
@property(nonatomic, unsafe_unretained) Class elementClass;

@end
