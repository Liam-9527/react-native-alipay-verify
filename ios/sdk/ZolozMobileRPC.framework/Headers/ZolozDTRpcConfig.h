//
//  ZolozDTRpcConfig.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//
/**
 * \code DTRpcConfig 用于处理 RPC 相关配置，如网关 URL，缓存策略等。
 */
@interface ZolozDTRpcConfig : NSObject

/** 网关 URL，不可为空 */
@property(nonatomic, strong) NSURL *gatewayURL;

/** 是否在状态栏中显示网络活动指示器，默认显示。*/
@property(nonatomic, assign) BOOL networkActivityIndicatorVisible;

/** 是否对请求参数进行GZip */
@property(nonatomic, assign) BOOL requestGZip;

/** 接口的名称. 如果设置了operationType，则该DTRpcConfig仅对该接口生效 */
@property(nonatomic, assign) NSString *operationType;

/** 接口请求超时 */
@property(nonatomic, assign) NSTimeInterval timeout;

/** 扩展配置信息 */
@property(nonatomic, strong) NSMutableDictionary* userInfo;

- (id)copy;

@end
