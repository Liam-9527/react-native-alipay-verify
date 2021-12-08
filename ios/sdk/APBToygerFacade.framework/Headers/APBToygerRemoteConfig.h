//
//  APFRemoteConfig.h
//  AppArch
//
//  Created by yukun.tyk on 8/29/16.
//  Copyright © 2016 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>


@class APBToygerSceneEnv, APBToygerVideo, APFRemoteConfig, APBToygerCollect, APBDragonflyLivenessConfig,APBGeminiLivenessConfig;
@class APBToygerNavigatePage, APBToygerAlgorithm, APBToygerTips;

/**
 *  协议配置
 */
@interface APBToygerRemoteConfig : NSObject

@property(nonatomic, strong)APBToygerSceneEnv *sceneEnv;
@property(nonatomic, strong)APBToygerNavigatePage *navi;
@property(nonatomic, strong)APBToygerCollect *coll;
@property (nonatomic, copy) NSDictionary *upload;
@property (nonatomic, copy) NSDictionary *algorithm;
@property(nonatomic, strong)APBToygerTips * faceTips;
@property(nonatomic, assign)NSInteger env;
@property(nonatomic, assign)NSInteger ui;
@property(nonatomic, copy)NSString *sdkVersion;
@property(nonatomic, strong)APBToygerVideo * video;
@property(nonatomic, copy)NSString *verifyMode;

+(APBToygerRemoteConfig *)defaultConfig;
+ (void)loadFromJSON:(NSString *)json toObject:(NSObject*) obj;
@end

/**
 *  场景配置
 */
@interface APBToygerSceneEnv : NSObject

@property(nonatomic, copy)NSString *sceneCode;
@property(nonatomic, copy)NSString *sceneType;

+(APBToygerSceneEnv *)defaultConfig;

@end

/**
 *  引导页配置
 */
@interface APBToygerNavigatePage : NSObject

@property(nonatomic, assign)BOOL enable;
@property(nonatomic, copy)NSString *url;

+ (APBToygerNavigatePage *)defaultConfig;

@end

/**
 *  采集场景配置
 */
@interface APBToygerCollect : NSObject

@property(nonatomic, assign)NSInteger retry;
@property(nonatomic, assign)CGFloat minangle;
@property(nonatomic, assign)CGFloat maxangle;
@property(nonatomic, assign)CGFloat near;
@property(nonatomic, assign)CGFloat far;
@property(nonatomic, assign)NSInteger minlight;
@property(nonatomic, assign)NSInteger time;
@property(nonatomic, assign)NSInteger light;
@property(nonatomic, assign)NSInteger imageIndex;
@property(nonatomic, assign)BOOL uploadLivePic;
@property(nonatomic, assign)NSInteger uploadMonitorPic;
@property(nonatomic, assign)BOOL progressbar;
@property(nonatomic, assign)BOOL uploadBestPic;
@property(nonatomic, assign)BOOL uploadPoseOkPic;
@property(nonatomic, assign)BOOL uploadBigPic;
@property(nonatomic, assign)BOOL authorization;
@property(nonatomic, assign)NSInteger mineDscore;
@property(nonatomic, assign)NSInteger mineVideo;
@property(nonatomic, strong)NSArray<NSString *> *actionMode;

+ (APBToygerCollect *)defaulConfig;

@end



/**
 *  视频设置
 */
@interface APBToygerVideo : NSObject

@property(nonatomic, assign)NSInteger width;
@property(nonatomic, assign)NSInteger height;
@property(nonatomic, assign)NSInteger duration;
@property(nonatomic, assign)NSInteger bitrate;
@property(nonatomic, assign)NSInteger fps;
@property(nonatomic, assign)BOOL    enable;       ;

+(APBToygerVideo *)defaultConfig;

@end



@interface APBToygerAlertConfig : NSObject

@property(nonatomic, copy)NSString * title;
@property(nonatomic, copy)NSString * message;
@property(nonatomic, copy)NSString * leftButtonText;
@property(nonatomic, copy)NSString * rightButtonText;
@property(nonatomic, assign)NSInteger returnCode;


@end

@interface APBToygerTips : NSObject

//required
@property(nonatomic, strong)APBToygerAlertConfig * timeoutAlert;
@property(nonatomic, strong)APBToygerAlertConfig * failAlert;
@property(nonatomic, strong)APBToygerAlertConfig * limitAlert;
@property(nonatomic, strong)APBToygerAlertConfig * networkErrorAlert;
@property(nonatomic, strong)APBToygerAlertConfig * interruptAlert;

@property (nonatomic, copy) NSString *sceneText;
@property (nonatomic, copy) NSString *bottomText;
@property (nonatomic, copy) NSString *topText_rectwidth;
@property (nonatomic, copy) NSString *topText_noface;
@property (nonatomic, copy) NSString *topText_blur;
@property (nonatomic, copy) NSString *topText_light;
@property (nonatomic, copy) NSString *topText_pitch;
@property (nonatomic, copy) NSString *topText_yaw;
@property (nonatomic, copy) NSString *topText_quality;
@property (nonatomic, copy) NSString *topText_integrity;
@property (nonatomic, copy) NSString *topText_max_rectwidth;
@property (nonatomic, copy) NSString *topText_stay;
@property (nonatomic, copy) NSString *topText_openness;
@property (nonatomic, copy) NSString *topText_blink;
@property (nonatomic, copy) NSString *brandTip;
@property (nonatomic, copy) NSString *stopScanTip;


@property (nonatomic, copy) NSString *garfield_guideTitle;
@property (nonatomic, copy) NSString *garfield_guideMsg;

//optional

@property(nonatomic, strong)APBToygerAlertConfig * unsurpportAlert;
@property(nonatomic, strong)APBToygerAlertConfig * systemVersionErrorAlert;
@property(nonatomic, strong)APBToygerAlertConfig * systemErrorAlert;
@property(nonatomic, strong)APBToygerAlertConfig * cameraNoPermissionAlert;
@property(nonatomic, strong)APBToygerAlertConfig * exitAlert;
@property(nonatomic, strong)APBToygerAlertConfig * authorizationAlert;
@property(nonatomic, strong)APBToygerAlertConfig * failNoRetryAlert;

+(APBToygerTips *)defaultConfig;

@end


