//
//  ASSSecureOpenSdk.h
//  APPSecuritySDK
//
//  Created by msq on 16/6/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASSTokenResult.h"

/*!
 @typedef ASSStatusCode
 
 Possible return codes
 @constant ASSStatusCodeOk                       Completed, No errors
 @constant ASSStatusCodeInvalidParam             input param invalid
 @constant ASSStatusCodeAppNameNil               appName is nil
 @constant ASSStatusCodeAppKeyNil                appKeyClient is nil
 @constant ASSStatusCodeConnectionError          network connection failure
 */
typedef NS_ENUM(NSInteger, ASSStatusCode)
{
    ASSStatusCodeOk = 0,
    ASSStatusCodeInvalidParam,
    ASSStatusCodeAppNameNil,
    ASSStatusCodeAppKeyNil,
    ASSStatusCodeConnectionError,
    
};

typedef void(^ASSSecureSdkCallbackOpen)(NSString* token, int errorCode);

@interface ASSSecureOpenSdk : NSObject

/*
 异步初始化vkeyid，推荐在app启动时和收银台页面加载时调用，SDK内部会根据时间戳和设备信息进行判断是否需要进行网络请求，无线程要求
 @param appName      应用名称
 
 @param appKeyClient 应用客户端密钥
 
 @param callback     初始化完成后的结果回调，以Token作为参数
 
 */
+ (void)initToken:(NSString *)appName appKeyClient:(NSString *)appKeyClient callback:(ASSSecureSdkCallbackOpen)callback;

+ (void)initToken:(NSString *)appName appKeyClient:(NSString *)appKeyClient parameters:(NSDictionary*)inArgs callback:(ASSSecureSdkCallbackOpen)callback;

/*
 VKEYID和VKEYID token的接口，无网络请求。
 同步调用前应当先调用过异步初始化接口
 
 如果异步初始化由于网络等原因失败，同步接口将返回降级方案：
 1）VKEYID将在旧版apdid存在的情况下返回旧版apdid，否则返回随机串
 2）VKEYID token将返回空字符串:@""
 */
+ (ASSTokenResultOpen*)getTokenResult;

/*
 *获取exactID
 */
+ (NSString*)getExactID;

/*
 *设置自定义的网关地址
 */
+ (void)setGatewayAddress:(NSString*)addr;

@end
