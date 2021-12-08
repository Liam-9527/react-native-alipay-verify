//
//  APBBisRequestBuilder.h
//  BioAuthEngine
//
//  Created by 晗羽 on 21/04/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BioAuthEngine/APBBisUploadGwRequest.h>
#import <BioAuthEngine/APBBehavLogModel.h>

@interface APBBisRequestBuilder : NSObject

#ifdef SUPPORT_PB
+ (APBBisUploadGwRequest *) buildRequestwithpubKey:(NSString *) pubKey
                                               token:(NSString *) bistoken
                                         contentData:(NSData *)content
                                           behaveLog:(BisBehavLog *)behavlog
                                       andCypherData:(NSData *) aesKeyData;
#else

+(APBBisUploadGwRequest *) buildRequestwithpubKey:(NSString *) pubKey
                                            token:(NSString *) bistoken
                                      contentData:(NSString *)content
                                        behaveLog:(BisBehavLog *)behavlog
                                    andCypherData:(NSString *) aesKeyData;
#endif

@end
