//
//  APLogSetting.h
//  APRemoteLogging
//
//  Created by tashigaofei on 15/3/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NSString * APLogGetUUID();
NSString * APLogGetUTDID();
NSString * APLogGetClientID();
NSString * APLogGetSystemType();
NSString * APLogGetSystemVersion();
NSString * APLogGetDeviceMode();
NSString * APLogGetUserID();
NSString * APLogGetClientVersion();
NSString * APLogGetPlatformID();
NSString * APLogGetConfigServerURL();
NSString * APLogGetLogServerURL();
NSString * APLogGetNetwork();
NSString * APLogGetLanguage();
NSString * APLogGetVoiceOver();
NSString * APLogGetCarrier();


void APLogSetClientVersion(NSString * clientVersion);
void APLogSetPlatformID(NSString * platformID);
void APLogSetConfigServerURL(NSString * url);
void APLogSetLogServerURL(NSString * url);
void APLogSetClientID(NSString * clientID);
void APLogSetLanguage(NSString * language);