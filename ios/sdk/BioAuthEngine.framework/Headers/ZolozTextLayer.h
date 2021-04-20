//
//  ZolozTextLayer.h
//  BioAuthEngine
//
//  Created by 王伟伟 on 2017/12/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@interface ZolozTextLayer : CATextLayer

@property (nonatomic, copy) NSAttributedString *attrStr;

- (CGSize)stringSize;

@end
