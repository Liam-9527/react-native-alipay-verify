//
//  ZimCameraServiceDirectway.h
//  ZolozSensorServices
//
//  Created by sanyuan.he on 2020/2/25.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#define ZIM_PLATFORM_SETTING_INFO_ALIYUN @"aliyun"
#define ZIM_PLATFORM_SETTING_INFO_ALITECH @"alitech"


@interface ZimCameraServiceDirectway : NSObject

@property(nonatomic , assign)UIDeviceOrientation orientation ;
@property(nonatomic , strong,nullable)NSString *forceDirection;
@property(nonatomic , assign)BOOL returnContent;
@property(nonatomic , strong ,nullable)NSData *imageContent;
@property(nonatomic , strong ,nullable)NSString*platformInfo;
@property(nonatomic , strong ,nullable)NSURL* photinusPath;
@property(nonatomic , strong ,nullable)NSURL* photinusInfo;
@property(nonatomic,strong,nullable)UIColor * circleColor;
@property(nonatomic,strong,nullable)UIColor * buttonColor;
@property(nonatomic,strong,nullable)UIColor * clickedColor;
@property(nonatomic,strong,nullable)NSString * ocrInfo;
@property(nonatomic , assign)BOOL returnContentUpload;


@property(nonatomic , strong ,nullable)NSData *faceData; // add for OCR
@property(nonatomic , strong ,nullable)NSData *countryData;  // add for OCR


+ (ZimCameraServiceDirectway *)sharedInstance;
@end

NS_ASSUME_NONNULL_END
