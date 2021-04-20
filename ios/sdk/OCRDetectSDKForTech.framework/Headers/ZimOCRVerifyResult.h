//
//  ZimOCRVerifyResult.h
//  AliyunIdentityManager
//
//  Created by 053508 on 2020/6/23.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZimOCRVerifyResult : NSObject

@property (nonatomic,strong) NSString* RetCode;//SInt32 productRetCode ;
@property (nonatomic,strong) NSString* nameString;
@property (nonatomic,strong) NSString* idString;
@property (nonatomic,strong) NSString* startTime;
@property (nonatomic,strong) NSString* endTime;
@property (nonatomic,strong) NSString* RetCodeSub;//retCodeSub ;
@property (nonatomic,strong) NSString* RetMessageSub;//retMessageSub ;

@end

NS_ASSUME_NONNULL_END
