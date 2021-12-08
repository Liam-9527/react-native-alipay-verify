//
//  ZolozDTRpcException.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ZolozDTRpcErrorCode.h"

/** The name of the RPC exception. */
extern NSString * const ZolozkDTRpcException;

/**
 * NSException is used to implement exception handling and contains information about an RPC exception.
 */
@interface ZolozDTRpcException : NSException

@property(nonatomic, assign) ZolozDTRpcErrorCode code;

+ (void)raise:(ZolozDTRpcErrorCode)code message:(NSString *)message;

+ (void)raise:(ZolozDTRpcErrorCode)code message:(NSString *)message userInfo:(NSDictionary*)userInfo;

@end
