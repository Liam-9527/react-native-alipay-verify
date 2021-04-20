//
//  DetectImageForOCRPhotoViewController.h
//  xMediaDemo
//
//  Created by 053508 on 2020/6/19.
//  Copyright © 2020 tao zeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ImageBlock)(UIImage *image, UIImage * _Nullable originImage);

@interface DetectImageForOCRPhotoViewController : UIViewController
@property (nonatomic, copy) ImageBlock imageblock;
@property (nonatomic,assign) NSInteger type;//类型为0表示身份证面，1为国徽面。

@end

NS_ASSUME_NONNULL_END
