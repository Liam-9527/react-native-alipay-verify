//
//  APVerifyService.h
//  SesameCreditMiniSDK
//
//  Created by leodi on 15/8/3.
//  Copyright (c) 2015年 SesameCredit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APVerifyService : NSObject

// 版本号：AlipayVerifySDK/2.1.1

+(APVerifyService *)sharedService;

/***
 * 获取bizCode
 * @return bizCode
 */
- (NSString *)bizCode;

/***
 * 获取当前sdk版本号
 */
- (NSString *)sdkVersion;
/***
 * 启动服务
 * @param url
 * @param target 目标controller, 商户controller必须基于navigation controller
 * @param block 返回结果在resultDic的字典中
 */
- (void)startVerifyService:(NSDictionary *)options
                    target:(id)targetVC
                     block:(void (^)(NSMutableDictionary * resultDic))block;
@end

