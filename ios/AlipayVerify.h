//
//  AlipayVerify.h
//
//  Created by Deng Xiang Hong on 2021/04/19.
//
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@interface AlipayVerify : RCTEventEmitter <RCTBridgeModule>
// 处理app回调
+(void) handleCallback:(NSURL *)url;
// 处理app回调
+(void) handleCallbackLaunchOptions:(NSDictionary *)launchOptions;
@end
