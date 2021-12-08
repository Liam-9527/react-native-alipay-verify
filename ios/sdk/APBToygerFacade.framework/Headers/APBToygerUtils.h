//
//  APFUtils.h
//  APFaceDetectBiz
//
//  Created by 晗羽 on 8/25/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <APBToygerFacade/APBToygerFacadeDefine.h>

//#import "APFaceDetectBizFacade.h"

//pipeInfo线程安全操作
static NSString *const kAPBPipeInfoMutexToken = @"";
static id __apb_thread_safe_object_for_key(NSMutableDictionary *pipeInfo, NSString *key){
    id ret;
    @synchronized(kAPBPipeInfoMutexToken){
        if ([pipeInfo isKindOfClass:[NSMutableDictionary class]] && [pipeInfo objectForKey: key]) {
            ret = [pipeInfo objectForKey:key];
        }
    }
    return ret;
}

//主线程同步操作
#define SYNC_MAINTHREAD_BEGIN_APBT           [APBToygerUtils APBToygerMainThread:^{
#define SYNC_MAINTHREAD_END_APBT             }];


//从pipeInfo中获取Object，线程安全
#define THREAD_SAFE_OBJECT_FOR_KEY(pipeInfo, key)   __apb_thread_safe_object_for_key(pipeInfo, key)

//向pipeInfo中添加或修改Object,线程安全
#define THREAD_SAFE_SET_OBJECT_FOR_KEY(pipeInfo, key, value)                                            \
    @synchronized(kAPBPipeInfoMutexToken){                                                                 \
        if ([pipeInfo isKindOfClass:[NSMutableDictionary class]] && key && value) {                     \
            [pipeInfo setObject:value forKey:key];}}

//删除PipeInfo中某个Object，线程安全
#define THREAD_SAFE_REMOVE_OBJECT_FOR_KEY(pipeInfo, key)                                                \
    @synchronized(kAPBPipeInfoMutexToken){                                                                 \
        if ([pipeInfo isKindOfClass:[NSMutableDictionary class]] && [pipeInfo objectForKey: key]) {     \
            [pipeInfo removeObjectForKey: key];}}

//将dict中对应value增加1
#define INCREASE_BY_ONE(pipeInfo, key){                                                                 \
    NSInteger num = [[pipeInfo objectForKey:key]integerValue]+1;                                        \
THREAD_SAFE_SET_OBJECT_FOR_KEY(pipeInfo, key, [NSNumber numberWithInteger:num]);}

//将dict中对应value减1
#define DECREASE_BY_ONE(pipeInfo, key){                                                                 \
    NSInteger num = [[pipeInfo objectForKey:key]integerValue]-1;                                        \
THREAD_SAFE_SET_OBJECT_FOR_KEY(pipeInfo, key, [NSNumber numberWithInteger:--num]);}



#define LOCK(locker, ...) dispatch_semaphore_wait(locker, DISPATCH_TIME_FOREVER); \
__VA_ARGS__; \
dispatch_semaphore_signal(locker);




@class MGLivenessDetectionFrameEncodedData;

@interface APBToygerUtils : NSObject

+ (void)APBToygerMainThread:(dispatch_block_t)block;

+ (NSString *)getTextContentforKey:(NSString*)keyName;
+ (NSString *)localizedTextForKey:(NSString *)key;
+ (NSBundle *)getBundle;

+ (int)getCodefrom:(NSString *)bisToken withLength:(int)codeLen;
//+ (NSString *)getActionNoticeByActionType:(APFLiveActionType) actionType;

//检查文件是否存在
+ (BOOL) checkFileunderPath:(NSString *) filePath;

//写入文件
//如果文件存在，不重写，返回失败。
//如果文件不再在，写入，返回写入结果
+ (BOOL) writeFileunderPath:(NSString *) filePath;

//删除文件
+ (BOOL) removeFileunderPath:(NSString *) filePath;

//随机文件名
+ (NSString *)randomString:(NSInteger)len;

+ (NSString *)localizedStringForKey:(NSString *)key;

+ (UIImage *)loadImageFromBundleNamed:(NSString *)imageName;

+ (UIWindow *)lastWindow;

+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;

@end




