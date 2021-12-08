//
//  DetectImageForOCRInfoViewController.h
//  xMediaDemo
//
//  Created by 053508 on 2020/6/8.
//  Copyright © 2020 tao zeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^DetectImageForOCRInfoBlock)(BOOL success, NSObject * _Nonnull result);



@class ZimRpcManager;
@interface DetectImageForOCRInfoViewController : UIViewController
@property (nonatomic, copy)DetectImageForOCRInfoBlock ocrInfoBlock;
@property(nonatomic, strong) ZimRpcManager * rpcManager;
@property (nonatomic,strong) NSString * certifyId;

@end

NS_ASSUME_NONNULL_END
