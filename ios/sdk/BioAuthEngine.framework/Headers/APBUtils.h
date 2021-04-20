//
//  APBUtils.h
//  BioAuthEngine
//
//  Created by richard on 27/08/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#include <sys/param.h>
#include <sys/mount.h>

#define SCREEN_WIDTH                [[UIScreen mainScreen]bounds].size.width                                    //屏幕宽度
#define SCREEN_HEIGHT               [[UIScreen mainScreen]bounds].size.height                                   //屏幕高度

//获取document目录
#define DOCUMENT_PATH               [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

//资源文件目录
#define ASSET_PATH                  [DOCUMENT_PATH stringByAppendingPathComponent:@"BioAuth"]

//返回不为nil的string
#define NONE_NIL_STRING(str)        (str ? str : @"")


#define SafeRelease(obj) if(obj){obj=nil;}

//主线程同步操作
#define SYNC_MAINTHREAD_BEGIN           [APBUtils APBMainThread:^{
#define SYNC_MAINTHREAD_END             }];

@interface APBUtils : NSObject

+ (NSString *)MD5WithData:(NSData *)data;

+ (BOOL)isWifi;

/**
 *  主线程同步操作，请调用宏版本
 */
+ (void)APBMainThread:(dispatch_block_t)block;

+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

+ (NSString*)convertToJSONString:(NSDictionary *)infoDict;

+ (NSString *)currentLanguage;

+ (NSString *)localizedStringForKey:(NSString *)key inBundle:(NSString *)bundle;

+ (NSString *)localizedStringForKey:(NSString *)key;

+ (long long)getTotalDiskSize;

+ (long long)getAvailableDiskSize;

+ (NSString*)deviceVersion;

+ (NSString *)osVersion;

+ (NSString *)appName;

+ (NSString *)appVersion;

+ (CMVideoDimensions)maxResolution:(AVCaptureDevicePosition) position;

@end
