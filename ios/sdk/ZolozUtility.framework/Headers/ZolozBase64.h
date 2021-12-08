//
//  ZolozBase64.h
//  ZolozUtility
//
//  Created by richard on 2018/8/13.
//  Copyright © 2018 com.alipay.iphoneclient.zoloz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZolozBase64 : NSObject

+(NSString *)encodeData:(NSData *)data;

+(NSData *)decodeString:(NSString *)str;

+(NSString *)stringByWebSafeEncodingData:(NSData *)data padded:(BOOL)pad;

@end
