//
//  APBZolozUploadTostView.h
//  APBToygerFacade
//
//  Created by richard on 28/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//
#import <UIKit/UIKit.h>
@interface APBZolozUploadToastView : UIView

@property(nonatomic,strong)UIActivityIndicatorView* indicator;

- (instancetype)initWithFrame:(CGRect)frame;

- (void)andSubViewWithFrame:(CGRect)frame AndText:(NSString *)text andDarkChoice:(BOOL)darkChoice andStartY:(float)startY;
@end
