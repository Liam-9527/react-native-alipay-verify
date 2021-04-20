//
//  CameraService.h
//  ZolozCameraService
//
//  Created by Tommy Li on 2017/8/23.
//  Copyright © 2017年 EyeVerify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#if defined(__cplusplus)
    #define ZOLOZ_EXPORT extern "C"
#else
    #define ZOLOZ_EXPORT extern
#endif


/// NSString keys that are used to specify configuration in ZolozCameraService initialization.
typedef NSString* const ZolozCameraInitKey;

/// NSString keys that are used to change configurations of ZolozCameraService;
typedef NSString* const ZolozCameraConfigKey;

/**
 Funtion type signature that is used for -takePicture: callbacks after a still image is captured.
 
 @param imageDataSampleBuffer The sample buffer of the still image. It is nil if any error occurred.
 @param error NSError that indicates any error during the capture process. It is nil if no error occurred.
 */
typedef void(^ZolozCameraTakePhotoCompletion)(CMSampleBufferRef imageDataSampleBuffer, NSError *error);

/// Initialization Key for specifying device position during initialization. Associated value must be a AVCaptureDevicePosition.
ZOLOZ_EXPORT ZolozCameraInitKey ZolozCameraInitKeyCaptureDevicePosition;

/// Initialization Key for specifying quality preset during initialization. Associated value must be a AVCaptureSessionPreset.
ZOLOZ_EXPORT ZolozCameraInitKey ZolozCameraInitKeySessionPreset;

/// Initialization Key for specifying video orientation during initialization. Associated value must be a AVCaptureVideoOrientation.
ZOLOZ_EXPORT ZolozCameraInitKey ZolozCameraInitKeyVideoOutputOrientation;

/// Initialization Key for specifying video mode during initialization. Associated value must be a ZolozCameraMode
ZOLOZ_EXPORT ZolozCameraInitKey ZolozCameraInitKeyMode;

/**
 Configuration Key for specifying focus point of interest. Associated value must be a CGPoint (converted to an NSString).
 
 Note that the associated value will be directly applied to camera without transformations, so regarding valid inputs please review focusPointOfInterest of AVCaptureDevice;
 */
ZOLOZ_EXPORT ZolozCameraConfigKey ZolozCameraConfigKeyFocusPointOfInterest;

/// Error domain name for ZolozCameraService
ZOLOZ_EXPORT NSString *const kZolozCameraErrorDomain;


/// Error codes used by ZolozCameraService to indicate the type of errors occured.
typedef NS_ENUM(NSInteger, ZolozCameraErrorCode) {
    
    /// Error code indicates that an invalid preset string is given during initialization.
    ZolozCameraUnsupportedPreset,
    
    /// Error code indicates that no devices are available with the specified configuration.
    ZolozCameraNotAvailable,
    
    /// Error code indicates that the capture session has failed.
    ZolozCameraSessionFailure,
};

/// Modes that ZolozCameraService supports
typedef NS_ENUM(NSInteger, ZolozCameraMode) {
    
    /// Video
    ZolozCameraModeVideo,
    
    /// Still Image
    ZolozCameraModeStillImage
    
};


/**
 A structure that stores camera configuration for associated camera service
 */
typedef struct camera_configuration_t{
    /// Focus Point of Interest
    CGPoint focusPointOfInterest;
}camera_configuration;


/**
 Delegate to comply in order to receive camera output.
 */
@protocol ZolozCameraServiceDelegate <NSObject>

@optional
/**
 This function will be called by ZolozCameraService to pass capture device output to the delegate.
 
 Implement this optional function and call -setDelegate: if you have set ZolozCameraModeVideo and wish to receive output.

 @param captureOutput Output source that triggered this delegation.
 @param sampleBuffer A CMSampleBuffer output from said output source.
 @param connection The AVCaptureConnection related to the output.
 */
- (void)cameraControllerCaptureOutput:(AVCaptureOutput *)captureOutput
                didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
                       fromConnection:(AVCaptureConnection *)connection;

@end

/**
 Main interface of ZolozCameraService.
 */
@interface ZolozCameraService : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>

/// Property that allows inspections the current configuration of ZolozCameraService
@property(nonatomic, assign, readonly)camera_configuration configuration;

/// Preview layer of the capture session. Add this layer as a sublayer to a view to inspect the device output. 
@property(nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

/// Get current video output size
@property (nonatomic, assign, readonly) CGSize videoOutputSize;


/**
 Do not use default NSObject initializer. Use initWithConfig:error: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize the camera service. 
 
 If ZolozCameraInitKeyCaptureDevicePosition is not specified in config, AVCaptureDevicePositionFront will be used as camera position.
 
 If ZolozCameraInitKeySessionPreset is not specified in config, AVCaptureSessionPresetHigh will be used as quality preset.
 
 If ZolozCameraInitKeyVideoOutputOrientation is not specified in config, output orientation will not be set. Video will be AVCaptureVideoOrientationLandscapeRight, and StillImage will be AVCaptureVideoOrientationPortrait.
 
 If ZolozCameraInitKeyMode is not specified in config, ZolozCameraModeVideo will be used as video output.

 @param config An NSDictionary that contains configuration keys and associated values to specify initialization requirements.
 @param errPtr An optional error receiver for initialization failures. Use nil if error information is not needed.
 @return If initialization is successful, a instance of ZolozCameraService is returned. Anything failture during initialization would cause this initialzer to return nil.
 */
- (instancetype)initWithConfig:(NSDictionary *)config error:(NSError **)errPtr;

/**
 Set delegate that ZolozCameraService can service

 @param delegate An instance of class that implements ZolozCameraServiceDelegate
 */
- (void)setDelegate:(id<ZolozCameraServiceDelegate>) delegate;

/**
 Change one configuration value in camera_configuration.

 @param key Configuration key
 @param value Properly formatted in-range value as a string
 @return YES if configuration was successfully changed. NO otherwise.
 */
- (BOOL)changeConfiguration:(NSString *)key
               desiredValue:(NSString *)value;

- (BOOL)setWhiteBalanceMode:(AVCaptureWhiteBalanceMode)mode;

- (BOOL)setExposureMode:(AVCaptureExposureMode)mode;

/**
 Start the capture session.
 
 The capture session needs to be started manually. This is a synchronous operation.
 */
- (void)startCamera;

/**
 Stop the capture session.
 
 This is a synchronous operation.
 */
- (void)stopCamera;

/**
 Capture a still image asynchronously.
 
 @param completion Completion delegate when the capture process finishes. For required parameters see ZolozCameraTakePhotoCompletion. 
 */
- (void)takePicture:(ZolozCameraTakePhotoCompletion)completion;

@end
