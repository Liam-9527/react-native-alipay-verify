//
//  ZolozDTRpcClient.h
//  APMobileRPC
//
//  Created by richard on 09/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ZolozDTRpcConfigScope.h"

extern NSString * const ZolozkDTRpcErrorCauseError;

@class ZolozDTRpcConfig;
@class ZolozDTRpcMethod;
@class ZolozDTRpcOperation;

@protocol ZolozDTRpcInterceptor;

/**
 * PRC client。
 */
@interface ZolozDTRpcClient : NSObject

+ (ZolozDTRpcClient *)defaultClient;

/**
 * 根据指定的 \code ZolozDTRpcMethod 执行一个 RPC 请求。
 *
 * @param method 一个 \code DTRpcCode 类型的实例，描述了 RPC 请求的相头信息。
 * @param params RPC 请求需要的参数。
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeMethod:(ZolozDTRpcMethod *)method params:(NSArray *)params;

/**
 * 根据指定的 \code ZolozDTRpcMethod 执行一个 RPC 请求。
 *
 * @param operation \code ZolozDTRpcOperation 的对象。
 *
 * @return 如果请求成功，返回指定类型的对象，否则返回 nil。
 */
- (id)executeOperation:(ZolozDTRpcOperation *)operation;

/**
 * 获取指定作用域中生效的配置信息。如果指定的作用域是临时的作用域，\code configForScope: 总是返回默认的配置对象。
 *
 * @param scope 要获取 PRC 配置的作用域。
 *
 * @return \code ZolozDTRpcConfig 类的一个实例，其中包含 PRC 相关的配置信息。
 */
- (ZolozDTRpcConfig *)configForScope:(ZolozDTRpcConfigScope)scope;

/**
 * 设置在指定的作用域中生效的配置对象。
 *
 * @param config 一个 \code DTRpcConfig 类型的对象，其中包含了 RPC 相关的配置信息。
 * @param scope RPC 配置生效的范围，该范围有效的值定义在 \code DTRpcConfigScope 枚举中。
 */
- (void)setConfig:(ZolozDTRpcConfig *)config forScope:(ZolozDTRpcConfigScope)scope;

/**
 *  添加RPC拦截器
 *
 *  @param interceptor 拦截器
 *
 *  @return RPCClient实例
 */
- (void)addInterceptor:(id <ZolozDTRpcInterceptor>)interceptor;

/**
 *  获取所有RPC拦截器
 *
 *  @return 拦截器列表
 */
- (NSArray *)interceptors;

/**
 * 取消operation请求。
 *
 * @param thread 当前运行operation的线程。
 */
- (void)cancelAllOperationsInThread:(NSThread *)thread;

@end
