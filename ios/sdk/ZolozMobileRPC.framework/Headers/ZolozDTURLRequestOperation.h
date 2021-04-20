//
//  ZolozDTURLRequestOperation.h
//  APMobileRPC
//
//  Created by richard on 12/02/2018.
//  Copyright © 2018 Alipay. All rights reserved.
//

/*!
 @class     DTURLRequestOperation
 @abstract  URL网络请求的处理线程类
 */
@interface ZolozDTURLRequestOperation : NSOperation <NSURLConnectionDataDelegate>

/*!
 @property  request
 @abstract  表示一个 URL 请求
 */
@property(nonatomic, strong) NSMutableURLRequest *request;

/*!
 @property  response
 @abstract  一个可以访问 URL 回应的编程接口
 */
@property(nonatomic, strong) NSURLResponse *response;

@property(nonatomic, strong) NSData *responseData;
@property(nonatomic, strong) NSString *responseString;

/*!
 @property  error
 @abstract  一个 NSError 错误对象，包含了网络连接为什么失败的原因
 */
@property(nonatomic, strong) NSError *error;

/*!
 @property  inputStream
 @abstract  网络处理的输入流
 */
@property(nonatomic, strong) NSInputStream *inputStream;

/*!
 @property  outputStream
 @abstract  网络处理的输出流
 */
@property(nonatomic, strong) NSOutputStream *outputStream;

/*!
 @property  runLoopModes
 @abstract  RunLoop消息处理模式
 */
@property(nonatomic, strong) NSSet *runLoopModes;

/*!
 @property  totalBytesRead
 @abstract  接收到数据的字节数
 */
@property(nonatomic, assign) NSInteger totalBytesRead;

/*!
 @property  lock
 @abstract  线程同步锁
 */
@property(nonatomic, strong) NSRecursiveLock *lock;

/*!
 @property  runningThread
 @abstract  一个线程对象，用于指定这个 URL 请求运行在哪个线程中
 */
@property(nonatomic, strong) NSThread *runningThread;

/*!
 @property  threadCreated
 @abstract  一个线程对象，用于标志是那个线程在运行这个operation请求
 */
@property(nonatomic, strong) NSThread *createdThread;

/*!
 @property  networkActivityIndicatorVisible
 @abstract  指定是否在状态栏中显示网络活动指示器。
 */
@property(nonatomic, assign) BOOL networkActivityIndicatorVisible;

/*!
 @property  requestBodyGZip
 @abstract  指定是否在对requestBody进行gzip。
 */
@property(nonatomic, assign) BOOL requestBodyGZip;

/*!
 @function  defaultOperationQueue
 @abstract  得到用于URL访问的缺省OperationQueue
 */
+ (NSOperationQueue *)defaultOperationQueue;

/*!
 @function  initWithRequest
 @abstract  生成一个URL网络请求的处理线程对象
 @param     request
 请求对象
 */
- (id)initWithRequest:(NSURLRequest *)request;

/*!
 @function  initWithRequest
 @abstract  生成一个URL网络请求的处理线程对象
 @param     request
 请求对象
 @param     outputStream
 网络处理的输出流
 */
- (id)initWithRequest:(NSURLRequest *)request outputStream:(NSOutputStream *)outputStream;

/**
 * 结束当前的请求操作。
 */
- (void)finish;

/*!
 @function      didStart
 @abstract      网络请求开始回调
 @discussion    可以在子类中重载处理
 */
- (void)didStart;

/*!
 @function      didFinish
 @abstract      网络请求结束回调
 @discussion    可以在子类中重载处理
 */
- (void)didFinish;

@end

