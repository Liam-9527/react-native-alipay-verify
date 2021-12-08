//
//  PoPGatewayNetwork.h
//  ZimDemo
//
//  Created by sanyuan.he on 2020/1/20.
//  Copyright © 2020 com.alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OATechGatewayNetwork : NSObject


-(void)bizSendContent:(NSDictionary*)serviceParameters completionBlock:(void (^) (BOOL success,NSURLResponse *response, NSData *data))completionBlock;

-(void)verifySendContent:(NSDictionary*)serviceParameters completionBlock:(void (^) (BOOL success,NSURLResponse *response, NSData *data))completionBlock;

-(void)sendInitFaceVerifyContent:(NSDictionary*)serviceParameters keyName:(NSString*)name completionBlock:(void (^) (BOOL success,NSURLResponse *response, NSData *data))completionBlock withEndPoint:(NSString*)point;


@end

NS_ASSUME_NONNULL_END
