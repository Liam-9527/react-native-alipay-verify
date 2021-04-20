//
//  ZIMIdentityManager.h
//  ZolozIdentityManager
//
//  Created by richard on 31/10/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AliyunIdentityManager/AliyunIdentityPublicApi.h>

//ext params keys
extern NSString *const kZIMInitOperationTypeKey;        //init operation type
extern NSString *const kZIMValidateOperationTypeKey;    //validate operation type
extern NSString *const kZIMGatewayURLKey;               //rpc gateway url
extern NSString *const kZIMRpcHeaderKey;                //ext rpc header
extern NSString *const kZIMCurrentViewControllerKey;    // current view controller
extern NSString *const kZIMFastUploadKey;
extern NSString *const kZIMBisProtocolKey;
extern NSString *const kZIMResponseKey;
extern NSString *const kZIMValidateResponseKey;
extern NSString *const kZIMCertNoKey;
extern NSString *const kZIMCertNameKey;
//@class ZIMResponse;


@interface ZolozIdentityManager : NSObject


@property(nonatomic, weak)id<ZIMMsgProxyDelegate> delegate;


+ (ZolozIdentityManager *)sharedInstance;

- (void)verifyWith:(NSString *)zimId
         extParams:(NSDictionary *)params
      onCompletion:(ZIMCallback)callback;


- (void)quit:(NSDictionary *) params
onCompletion:(ZIMQuitCallback)callback;

+ (NSDictionary *)getMetaInfo;

+ (NSString *)version;

#ifdef FEATURE_LOCAL_MATCH
+ (void)processValidateResult:(BOOL) result forUser:(NSString *) userid andzimID:(NSString *) zimID;

+ (void)processValidateResult:(BOOL) result forUser:(NSString *) userid;
#endif

@end

