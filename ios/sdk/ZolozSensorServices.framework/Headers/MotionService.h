//
//  ZolozMotionService.h
//  EVDeviceSensor
//
//  Created by yukun.tyk on 30/12/2016.
//  Copyright © 2016 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct zoloz_vec3_t {
    float x;
    float y;
    float z;
}zoloz_vec3;

typedef struct zoloz_vec4_t {
    float w;
    float x;
    float y;
    float z;
}zoloz_vec4;

typedef struct zoloz_motion_data_t{
    zoloz_vec4 attitude;
    zoloz_vec3 acceleration;
    zoloz_vec3 rotation;
    zoloz_vec3 gravity;
    zoloz_vec3 magnetic;
}zoloz_motion_data;

@protocol ZolozMotionServiceDelegate <NSObject>

- (void)motionDataDidUpdate:(zoloz_motion_data) motionData;

@end

@interface ZolozMotionService : NSObject

@property(nonatomic, assign, readonly)zoloz_motion_data motionData;

- (void)setDelegate:(id<ZolozMotionServiceDelegate>)delegate;

- (void)startUpdateWithInterval:(NSTimeInterval)interval;

- (void)stop;

@end
