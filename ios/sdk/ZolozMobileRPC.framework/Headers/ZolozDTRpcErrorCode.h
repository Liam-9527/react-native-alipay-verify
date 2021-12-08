//
//  ZolozDTRpcErrorCode.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

typedef enum ZolozDTRpcErrorCode
{
    
    /** 网络连接错误。*/
    kDTRpcNetworkError,
    
    /** 服务端返回的数据为空。 */
    kDTRpcEmptyResponse,
    
    /** 服和端返回的 JSON 字符串格式不正确，不能成功转换成 JSON 对象。 */
    kDTRpcInvalidJSONString,
    
    /** 反序列化 JSON 对象出错。*/
    kDTRpcDecodeObjectError,
    
    /** 网络已取消。 */
    kDTRpcNetworkCancelled,
    
} ZolozDTRpcErrorCode;

