//
//  AFECircularView.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 01/11/2016.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BioAuthEngine/AFEScanViewDelegate.h>
@class AFEStatusBar, AFECircleProgressBar, APBBlurView;

@protocol AFECircularViewProtocol <NSObject>

- (void)onStopScan;

@end

@interface AFECircularView : UIView<AFEScanViewProtocol>

@property (strong, nonatomic) AFEStatusBar *statusBar;
@property (nonatomic, strong) CALayer *compactLayer;
@property (nonatomic, assign) float cameraStartY;
- (void)showPercent:(CGFloat)stage;
- (void)showtip:(NSString *)tip;
- (void)showBottomTip:(NSString *)bottomTip;
- (void)addCameraPreviewLayer:(CALayer *)cameraPreviewLayer;
- (void)powerByLayerHidden:(BOOL)hidden;

- (void)setStopScanButtonHidden:(BOOL)hidden;
- (void)setMaskImage:(UIImage *)bestImage;
- (void)startWave;
- (void)stopWave;
- (void)setAFECirViewDelegate:(id<AFECircularViewProtocol>)delegate;
- (void)showBrandTip:(NSString *)brandTip;
- (void)showStopScanTip:(NSString *)stopScanTip;
- (void)hideViewList;
- (void)showViewList;
@end

