//
//  ZolozLogMonitor.h
//  BioAuthEngine
//
//  Created by richard on 22/03/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozLogMonitor : NSObject

- (instancetype)initWithBizInfo:(NSDictionary *)bizInfo;

- (void)addPublicLog:(NSDictionary *)logDic;
/*
 *  添加埋点, param1为MD5(bis_token), param2=sequence_id
 *  param3: 第二个埋点数据, NSString或者NSNumber
 *  param4: 第三个埋点数据, NSString或者NSNumber
 *  seed:   埋点seesId
 *  ucid:   埋点ucid
 *  formattedParam: 附加参数
 */
- (void)addMonitorLoagWithActionId:(NSString *)actionId
                            param3:(NSObject *)p3
                            param4:(NSDictionary *)p4
                            seedId:(NSString *)seed
                              ucid:(NSString *)ucid
                    formattedParam:(NSDictionary *)param;

//添加私有埋点
- (void)addPrivateMonitorLoagWithparam1:(NSObject *)p1
                                 param2:(NSObject *)p2
                                 param3:(NSDictionary *)p3;

+ (void)addPrivateMonitorLogWithBisToken:(NSString *)bisToken
                                  param2:(NSString *)p2
                                  param3:(NSString *)p3
                                  param4:(NSDictionary *)p4;

+(NSDictionary *)getPublicLogDic:(NSDictionary *)publicParam;

+(NSDictionary *)getExtLogDic:(NSDictionary *)p4;

+(void)Zoloz_writeLogWithActionId:(NSString *)actionId
                        extParams:(NSArray *)extParams
                            appId:(NSString *)appId
                             seed:(NSString *)seed
                             ucId:(NSString *)ucId;

@end
