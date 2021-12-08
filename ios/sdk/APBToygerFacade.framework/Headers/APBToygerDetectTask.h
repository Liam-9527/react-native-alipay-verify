//
//  APBToygerDetectTask.h
//  APBToygerFacade
//
//  Created by Dan Cong on 29/1/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <APBToygerFacade/APBToygerBaseTask.h>

/**
 检测基类，用于下沉多种UI(樱桃和加菲)下通用的逻辑
 */
@interface APBToygerDetectTask : APBToygerBaseTask

- (void)_addDarkScreen;

- (void)_showProgress:(CGFloat)progress;

- (void)_showAlertViewBy:(NSDictionary *)alertParam;

@end
