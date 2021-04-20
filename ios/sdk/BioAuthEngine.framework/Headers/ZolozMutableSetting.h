//
//  ZolozMutableSetting.h
//  BioAuthEngine
//
//  Created by richard on 24/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozMutableSetting : NSObject

+ (instancetype)getInstance;

- (NSString *)gatewayURL;

- (NSDictionary *)headConfig;

- (NSString *)zolozInitRequestOperationType;

- (NSString *)validateRequestOperationType;

- (NSString *)bioAuthEngineVersion;

- (NSString *)onlinePubKey;

- (NSString *)testPubKey;


@end
