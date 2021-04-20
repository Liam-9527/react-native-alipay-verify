//
//  ZolozDTRpcOperation.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZolozDTRpcBaseOperation.h"

@class ZolozDTRpcMethod;

/**
 * 执行 RPC 请求的 operation。
 *
 * DTRpcOperation 类在实例化时，把调用方传入的参数（通常是一个数组，数组中可以是普通对象、字符串或是数字）序列化为
 * JSON 格式的字符串。在收到服务端的回应后，把返回的 JSON 字符串再转换成指定 Class 的对象。
 *
 * 客户端以表单的形式把请求的数据提交到服务端，有三个表单项：
 *    <ul>
 *        <li>mobilerpc - 协议版本号</li>
 *        <li>operationType - 应用名|服务名|接口名</li>
 *        <li>requestData - JSON序列化后的数据</li>
 *    </ul>
 *
 */
@interface ZolozDTRpcOperation : ZolozDTRpcBaseOperation

@property(nonatomic, assign) NSTimeInterval startTime;


/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 *
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(ZolozDTRpcMethod *)method params:(NSArray *)params;

/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 * @param timeout 超时时间
 *
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(ZolozDTRpcMethod *)method params:(NSArray *)params timeout:(NSTimeInterval)timeout;

/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 * @param headerFields 在request中添加headerField。
 *
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(ZolozDTRpcMethod *)method params:(NSArray *)params headerFields:(NSDictionary*)fields;

/**
 * 返回 \ZolozDTRpcMethod 对象。
 */
- (ZolozDTRpcMethod *)method;

/**
 * 返回请求参数数组。
 */
- (NSArray *)params;

/**
 * 获取 RPC 请求成功的对象，如果调用失败，则返回 nil。
 *
 * @return 服务端返回的对象。
 */
- (id)resultObject;

/**
 *  RPC请求上下文
 *
 *  @return 上下文
 */
- (NSMutableDictionary *)userInfo;

@end
