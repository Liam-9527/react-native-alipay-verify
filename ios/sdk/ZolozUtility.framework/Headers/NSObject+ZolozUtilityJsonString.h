//
//  NSObject+ZolozUtilityJsonString.h
//  ZolozUtility
//
//  Created by richard on 2018/8/15.
//  Copyright © 2018 com.alipay.iphoneclient.zoloz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (ZolozUtilityJsonString)

- (NSMutableDictionary *_Nonnull)dictionary;
- (id _Nonnull )idFromObject:(nonnull id)object;

@end
