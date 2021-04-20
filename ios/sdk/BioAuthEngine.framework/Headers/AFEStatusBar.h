//
//  AFEStatusBar.h
//  FaceEyePrint
//
//  Created by yukun.tyk on 12/17/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol IStatusBarDelegate <NSObject>
- (void)onButtonCancel;
@optional
- (void)onSoundStatusChanged:(BOOL)newStatus;
@end

@interface AFEStatusBar : UIView

- (void)onButtonCancel;

- (void)setDelegate:(id<IStatusBarDelegate>)delegate;

- (void)setTransparent:(CGFloat) alpha;

- (void)setCancelButtonHidden:(BOOL)hidden;


@end
