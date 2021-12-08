//
//  APFBaseTask.h
//  APFaceDetectBiz
//
//  Created by 晗羽 on 8/25/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <BioAuthEngine/IBioAuthTask.h>
#import <BioAuthEngine/APBTaskContext.h>
#import <BioAuthEngine/APBLogger.h>
#import <BioAuthEngine/ZolozLogMonitor.h>
#import <BioAuthEngine/AFEAlertView.h>
#import <APBToygerFacade/APBToygerUtils.h>
#import <APBToygerFacade/APBToygerRemoteConfig.h>
#import <APBToygerFacade/APBToygerBehavlogManager.h>
//#import "APBToygerDataCenter.h"
#import <BioAuthEngine/BioAuthCommonSetting.h>
#import <APBToygerFacade/APBToygerViewController.h>

@class ZolozLogMonitor,APBToygerDataCenter;

typedef void (^APFAlertExtraAction)();

@interface APBToygerBaseTask : NSObject <IBioAuthTask>

//协议定义的属性
@property(nonatomic, copy)NSString *taskName;                           //任务名
@property(nonatomic, strong)APBTaskContext *context;                    //任务数据
@property(nonatomic, weak)NSMutableDictionary *pipeInfo;              //共享数据
//公用属性
@property(nonatomic, weak)UIViewController *parentViewController;       //父viewController
@property(nonatomic, weak)APBToygerViewController *currentViewController;      //当前viewController
@property(nonatomic, weak)UIView *currentView;                          //当前显示的界面
@property(nonatomic, copy)commandBlock bioCommandBlock;                 //对框架进行操作的block
@property(nonatomic, strong)APBToygerRemoteConfig * bisConfig;                //bis下放的配置参数
@property(nonatomic, strong)APBToygerDataCenter * dataCenter;                 //行为日志
@property(nonatomic, copy)NSString *bisToken;                         //bisToken
@property(nonatomic, assign)NSInteger currentRetryCnt;                  //当前重试次数
@property(nonatomic, assign)BOOL soundStatus;                           //当前声音状态
//@property(nonatomic, assign)BOOL isLoginMode;                           //当前场景是否为登录场景
@property(nonatomic, assign)BOOL isMYBank;                              //是否是网商银行
@property(nonatomic, strong)ZolozLogMonitor *monitor;                        //埋点

- (void)exitWithResult:(APBResultType)result failReason:(NSString *)failReason retCodeSub:(NSString *)retCodeSub retMessageSub:(NSString *)retMessageSub;

/**
 *  用户选择重试
 */
- (void)handleRetryActionWithScene:(NSString *)scene
                       buttonTitle:(NSString *)title
                         extAction:(APFAlertExtraAction)action;

/**
 *  用户选择退出
 */
- (void)handleExitActionWithScene:(NSString *)scene
                      buttonTitle:(NSString *)title
                       exitReason:(APBResultType)reason
                        extAction:(APFAlertExtraAction)action;

/**
 *  用户选择继续
 */
- (void)handleContinueActionWithScene:(NSString *)scene
                          buttonTitle:(NSString *)title
                            extaction:(APFAlertExtraAction)action;

/**
 *  消除VC的方式，加菲和樱桃不同
 */
- (void)dismissViewControllerAnimated: (BOOL)flag completion:(void (^ __nullable)(void))completion;

@end
