//
//  ZolozMonitorCommonData.h
//  BioAuthEngine
//
//  Created by richard on 19/03/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozMonitorCommonData : NSObject

@property (nonatomic,strong) NSString* serviceLevel;


+ (instancetype)getInstance;

- (NSString *)getToken;

- (NSInteger)getIndex;

- (void)resetValue;

- (NSDictionary *)getCommonMonitorData;

- (NSDictionary *)getBase64CommonMonitorData;

@end
