//
//  ZIMRpcManager.h
//  ZolozIdentityManager
//
//  Created by richard on 26/02/2018.
//  Copyright © 2018 com.alipay.iphoneclient.zoloz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AliyunIdentityManager/ZimInitRequest.h>
#import <AliyunIdentityManager/ZimValidateRequest.h>
#import <BioAuthEngine/APBGatewayFacade.h>
/**
 *  rpc结果回调
 *
 *  @param success 网络交互是否成功(不代表服务端返回的结果)
 *  @param result  服务端返回的结果
 */
typedef void (^rpcCompletionBlock)(BOOL success, NSObject *result);



@interface ZimRpcManager : NSObject

@property(nonatomic, strong) APBGatewayFacade * gatewayFacade;

/**
 /为了兼容旧版本，这是过度时期的产物，后面会删除该函数
 */

- (void)doInitRequest:(ZimInitRequest * )request withcompletionBlock:(rpcCompletionBlock)blk;

/**
 /为了兼容旧版本，这是过度时期的产物，后面会删除该函数
 */

- (void)doValidateRequest:(ZimValidateRequest *)request withcompletionBlock:(rpcCompletionBlock)blk;

//代理模式
- (void)doValidateRequetViaDelegate:(ZimValidateRequest * )request withcompletionBlock:(rpcCompletionBlock)blk;


/**
 *  zim init request
 *
 *  @param request 初始化请求
 *  @param blk     网络请求结果回调处理，result为ZimInitResponse
 */
- (void)doFastUploadInitRequest:(ZimInitRequest * )request withcompletionBlock:(rpcCompletionBlock)blk;
/**
 *  zim validate request
 *
 *  @param request validate请求
 *  @param blk     网络请求结果回调处理，result为ZimValidateResponse
 */
- (void)doFastUploadValidateRequest:(ZimValidateRequest * )request withcompletionBlock:(rpcCompletionBlock)blk;


//OCR接口
- (void) doSendOCRContent:(NSString*)certifyId idSide:(NSString*)side withImage:(NSData*)imageData withcompletionBlock:(rpcCompletionBlock)blk;

// SMS 请求接口
- (void)getSMSCode:(NSDictionary*)serviceParameters completionBlock:(rpcCompletionBlock)blk;

// SMS 验证接口
- (void)verifySMSCode:(NSDictionary*)serviceParameters completionBlock:(rpcCompletionBlock)blk;

@end
