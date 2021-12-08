//
//  ASSTokenResult.h
//  APPSecuritySDK
//
//  Created by xingchen on 15/7/31.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASSTokenResultOpen: NSObject

@property (nonatomic, strong) NSString* vkeyidToken;
@property (nonatomic, strong) NSString* clientKey;
@property (nonatomic, strong) NSString* vkeyid;

@end
