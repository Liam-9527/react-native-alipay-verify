//
//  ZolozDTRpcContext.h
//  ZolozMobileRPC
//
//  Created by richard on 23/02/2018.
//  Copyright © 2018 com.alipay.iphoneclient.zoloz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozDTRpcContext : NSObject

/**
 * 设置rpc请求header
 * @param 字典类型的header
 */
+(void)setRpcHeader:(NSDictionary*)header;
/**
 * 获取rpc请求header
 * @return 获取字典类型的请求header
 */

+(NSDictionary*)getRpcHeader;
/**
 *  移除rpc请求的Header
 */
+(void)removeRpcHeader;
/**
 *  设置是否是前台rpc
 */
+(void)setForegroundRPC:(BOOL)isForeground;
/**
 *  获取是否是前台rpc 默认是yes
 */
+(BOOL)isForegroundRPC;

/**
 *  设置网络层是否需要显示限流页面
 */
+(void)setShouldShowFlow:(BOOL)showFlow;
/**
 *  获取网络层是否需要显示限流页面
 */
+(BOOL)shouldShowFlow;
/**
 * 设置rpc响应header
 * @param 字典类型的header
 */
+(void)setRpcRespHeader:(NSDictionary *)header;
/**
 * 获取rpc响应的header
 * @return 获取字典类型的响应header
 */
+(NSDictionary*)getRpcRespHeader;

@end
