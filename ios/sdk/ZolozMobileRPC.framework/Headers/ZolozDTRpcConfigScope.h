//
//  ZolozDTRpcConfigScope.h
//  APMobileRPC
//
//  Created by richard on 11/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

/**
 * PRC 配置的作用域。
 */
typedef enum ZolozDTRpcConfigScope
{
    
    /** 全局生效。 */
    kDTRpcConfigScopeGlobal,
    
    /** 本地线程生效。 */
    kDTRpcConfigScopeLocalThread
    
} ZolozDTRpcConfigScope;

