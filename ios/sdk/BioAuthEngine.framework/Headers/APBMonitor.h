//
//  APBMonitor.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 1/12/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface APBMonitor : NSObject

- (instancetype)initWithBizInfo:(NSDictionary *)bizInfo;

- (instancetype)initWithBizInfo:(NSDictionary *)bizInfo
                          appid:(NSString *)appid;

- (NSString *)token;

#pragma mark - Public Log
/**
 添加公共埋点
 
 @param logDic 埋点数据
 */
- (void)addPublicLog:(NSDictionary *)logDic;

/**
 移除某一个公共埋点
 
 @param key 埋点的key的名字
 */
- (void)removePublicLogForKey:(NSString *)key;

/**
 移除所有的公共埋点
 */
- (void)removeAllPublicLog;

/**
 所有的公共埋点日志
 
 @return 返回所有的公共埋点日志，有埋点返回所有埋点，没有埋点返回空字典
 */
-(NSDictionary *)allPublicLogs;
#pragma mark -

/*
 *  添加埋点
 *  param1: 第二个埋点数据, NSString或者NSNumber
 *  param2: 第三个埋点数据, NSString或者NSNumber
 *  param3: 第四个埋点数据，必须是NSDictionary
 *  seed:   埋点seesId
 *  ucid:   埋点ucid
 */
- (void)addMonitorLoagWithActionId:(NSString *)actionId
                            param1:(NSObject *)p1
                            param2:(NSObject *)p2
                            param3:(NSDictionary *)p3
                            seedId:(NSString *)seed
                              ucid:(NSString *)ucid;

/*
 *  添加埋点
 *  param1: 第二个埋点数据, NSString或者NSNumber
 *  param2: 第三个埋点数据, NSString或者NSNumber
 *  param3: 第四个埋点数据，必须是NSDictionary
 *  seed:   埋点seesId
 *  ucid:   埋点ucid
 *  formattedParam: 附加参数
 */
- (void)addMonitorLoagWithActionId:(NSString *)actionId
                            param1:(NSObject *)p1
                            param2:(NSObject *)p2
                            param3:(NSDictionary *)p3
                            seedId:(NSString *)seed
                              ucid:(NSString *)ucid
                    formattedParam:(NSDictionary *)param;

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

@end

