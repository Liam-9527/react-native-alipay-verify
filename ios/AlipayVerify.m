//
//  AlipayVerify.m
//
//  Created by Deng Xiang Hong on 2021/04/19.
//
#import "AlipayVerify.h"
#import<AlipayVerifySDK/APVerifyService.h>
#import <ZolozIdentityManager/ZolozSdk.h>
#import <AlipayVerifySDK/APVerifyService.h>

@implementation AlipayVerify {
    bool hasListeners;
    
}

RCT_EXPORT_MODULE()

// 获取 bizCode
// 每开启一次认证都需客户端重新获取一次 bizCode 并将其传入服务端，作为  alipay.user.certify.open.initialize (身份认证初始化服务) 接口中 biz_code 参数值。
RCT_REMAP_METHOD(getBizCode,
                 withResolver:(RCTPromiseResolveBlock)resolve
                 withRejecter:(RCTPromiseRejectBlock)reject)
{
    [ZolozSdk init];
    NSString *bizcode = [[APVerifyService sharedService] bizCode];
    resolve(bizcode);
}

// 开始刷脸服务 (未安装支付宝时无法打开内置SDK进行认证)
// 客户端与服务端中 bizCode 参数值需保持一致。
RCT_REMAP_METHOD(verify,
                 verifyWithA:(nonnull NSString*)certifyId withB:(nonnull NSString*)certifyUrl
                 withResolver:(RCTPromiseResolveBlock)resolve
                 withRejecter:(RCTPromiseRejectBlock)reject)
{
    NSString *bizcode = [[APVerifyService sharedService] bizCode];
    
//    UIWindow *window = [UIApplication sharedApplication].keyWindow;
//    NSLog(@"window =  %@", window);
//    UIViewController *rootViewController = window.rootViewController;
//    NSLog(@"rootViewController =  %@", rootViewController);
//    UINavigationController *navigationController = rootViewController.navigationController;
//    NSLog(@"navigationController =  %@", navigationController);
    
    [[APVerifyService sharedService] startVerifyService:@{@"url": certifyUrl?:@"test-certifyUrl",
                                                          @"certifyId": certifyId?:@"test-certifyId",
                                                          @"ext": @"test-extInfo",@"bizcode":bizcode}
                                                 target:self
                                                  block:^(NSMutableDictionary * resultDic){
        resolve([resultDic valueForKey:@"resultStatus"]);
    }];
}

// 处理回调
+(void) handleCallback:(NSURL *)url
{
    NSLog(@"url =  %@", url);
    if ([url.host isEqualToString:@"safepay"]) {
        
    }
}

// 处理回调
+(void) handleCallbackLaunchOptions:(NSDictionary *)launchOptions
{
    NSLog(@"launchOptions =  %@", launchOptions);
}

- (NSArray<NSString *> *)supportedEvents
{
    return @[@"EventReminder"];
}

- (void)calendarEventReminderReceived:(NSNotification *)notification
{
    NSString *eventName = notification.userInfo[@"name"];
    if (hasListeners) { // Only send events if anyone is listening
      [self sendEventWithName:@"EventReminder" body:@{@"name": eventName}];
    }
}

// 在添加第一个监听函数时触发
-(void)startObserving {
    hasListeners = YES;
    // Set up any upstream listeners or background tasks as necessary
}

// Will be called when this module's last listener is removed, or on dealloc.
-(void)stopObserving {
    hasListeners = NO;
    // Remove upstream listeners, stop unnecessary background tasks
}

@end
