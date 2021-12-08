//
//  ToygerFaceFrame.h
//  ToygerAlgorithm
//
//  Created by 王伟伟 on 2018/1/22.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToygerService/ToygerFrame.h>

typedef NS_ENUM(NSInteger, ToygerMessage) {
    TOYGER_Message_Image_Perfect = 0,
    TOYGER_Message_No_Face,
    TOYGER_Message_Distance_Too_Far,
    TOYGER_Message_Distance_Too_Close,
    TOYGER_Message_Face_Not_In_Center,
    TOYGER_Message_Bad_Pitch,
    TOYGER_Message_Bad_Yaw,
    TOYGER_Message_Is_Moving,
    TOYGER_Message_Bad_Brightness,
    TOYGER_Message_Bad_Quality,
    TOYGER_Message_Bad_Eye_Openness,
    TOYGER_Message_Blink_Openness,
    TOYGER_Message_Stack_Time,
};

typedef NS_ENUM(NSInteger, ToygerStaticMessage) {
    TOYGER_Static_Message_NoLiveness = 0,
    TOYGER_Static_Message_BlinkLiveness,
};

@interface ToygerFaceFrame : ToygerFrame<NSCopying>

@property (nonatomic, assign) ToygerMessage message;
@property (nonatomic, assign) ToygerStaticMessage staticMessage;
@property (nonatomic, assign) BOOL has_face;
@property (nonatomic, assign) int brightness;
@property (nonatomic, assign) int distance;
@property (nonatomic, assign) BOOL face_in_center;
@property (nonatomic, assign) BOOL is_moving;
@property (nonatomic, assign) BOOL good_quality;
@property (nonatomic, assign) BOOL good_pitch;
@property (nonatomic, assign) BOOL good_yaw;
@property (nonatomic, assign) BOOL eyeBlink;
@property (nonatomic, assign) CGFloat progress;

@end
