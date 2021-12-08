//
//  ZolozDTRpcAsyncCaller.h
//  APMobileRPC
//
//  Created by richard on 12/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozDTRpcAsyncCaller : NSObject

+ (ZolozDTRpcAsyncCaller *)callAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;

- (void)startAsyncBlock:(void (^)(void))block completion:(void (^)(void))completion;
- (void)cancel;

- (BOOL)isFinished;
- (BOOL)isCancelled;

- (NSThread *)asyncThread;

- (void)handleException:(NSException *)exception;

@end
