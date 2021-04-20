//
//  ZIMIdentityManager.h
//  AliyunIdentityManager
//
//  Created by richard on 31/10/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



//version 1.3.7


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
extern NSString *const ZIM_EXT_PARAMS_KEY_OCR_BOTTOM_BUTTON_COLOR; //设置颜色的值，值内容为:#FFFFFF 格式，必须为6位
extern NSString *const ZIM_EXT_PARAMS_KEY_OCR_BOTTOM_BUTTON_CLICKED_COLOR; //设置按钮点击颜色的值，值内容为:#FFFFFF 格式 ,必须为6位
extern NSString *const ZIM_EXT_PARAMS_KEY_USE_VIDEO;
extern NSString *const ZIM_EXT_PARAMS_KEY_OCR_FACE_CIRCLE_COLOR;
@class ZIMResponse;



typedef void (^ZIMCallback)(ZIMResponse *response);
typedef void (^ZIMQuitCallback)(BOOL succes, NSDictionary * reason);
typedef void(^ZIMMsgProxyHandler)(NSDictionary *params);

//msg字典中{@"requestData",""}的字符串是ZimValidateRequest对象
//PB格式下：是ZimValidateRequest对象bytes内容做base64生成的字符串。
//JSON格式下，将ZimValidateRequest对象序列化成json字符串，然后base64生成的字符串

@protocol ZIMMsgProxyDelegate <NSObject>
- (void)didReceivedMsg:(NSDictionary *)msg withHandler:(ZIMMsgProxyHandler)handler;
@end


@interface AliyunIdentityManager : NSObject


@property(nonatomic, weak)id<ZIMMsgProxyDelegate> delegate;


+ (AliyunIdentityManager *)sharedInstance;

- (void)verifyWith:(NSString *)zimId
         extParams:(NSDictionary *)params
      onCompletion:(ZIMCallback)callback;

- (NSArray *)getlogArray;


- (void)quit:(NSDictionary *) params
onCompletion:(ZIMQuitCallback)callback;

+ (NSDictionary *)getMetaInfo;

+ (NSString *)version;

+ (NSString *)protocolVersion;

#ifdef FEATURE_LOCAL_MATCH
+ (void)processValidateResult:(BOOL) result forUser:(NSString *) userid andzimID:(NSString *) zimID;

+ (void)processValidateResult:(BOOL) result forUser:(NSString *) userid;
#endif

-(void) sendlog:(NSDictionary*)paramDic withSeedID:(NSString*)seedId;

@end

