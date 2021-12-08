//
//  DetectImageForOCRInfoErrorTipViewController.h
//  xMediaDemo
//
//  Created by 053508 on 2020/6/16.
//  Copyright © 2020 tao zeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


//点击时间的回调
typedef void(^CustomAlertDismissBlock)(UIButton *button);

@interface DetectImageForOCRInfoErrorTipViewController : UIViewController
+ (UIViewController *)showCustomerAlertViewControllerWithSuperController:(UIViewController *)superController withType:(NSInteger)type actionBlock:(CustomAlertDismissBlock)customBlock;
@property (nonatomic, copy) CustomAlertDismissBlock dismissBlock;

@end

NS_ASSUME_NONNULL_END
