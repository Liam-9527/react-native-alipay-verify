require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-alipay-verify"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :ios => "10.0" }
  s.source       = { :git => "https://www.react-native.cn/docs/native-modules-setup.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,m,mm}"
  s.libraries = "c++","z","c++abi","icucore"
  s.frameworks = "WebKit","UserNotifications","Accelerate","AssetsLibrary","ImageIO","AVFoundation","CoreMotion","CoreMedia","CoreLocation","CoreFoundation","QuartzCore","CoreTelephony","CoreGraphics"
  s.ios.vendored_frameworks = "ios/sdk/AlipayVerifySDK.framework", "ios/sdk/AliyunIdentityManager.framework", "ios/sdk/APBToygerFacade.framework", "ios/sdk/APPSecuritySDK.framework", "ios/sdk/BioAuthAPI.framework", "ios/sdk/BioAuthEngine.framework", "ios/sdk/MPRemoteLogging.framework", "ios/sdk/OCRDetectSDKForTech.framework", "ios/sdk/ToygerService.framework", "ios/sdk/ZolozIdentityManager.framework", "ios/sdk/ZolozMobileRPC.framework", "ios/sdk/ZolozOpenPlatformBuild.framework", "ios/sdk/ZolozSensorServices.framework", "ios/sdk/ZolozUtility.framework"
  s.vendored_frameworks = "AlipayVerifySDK.framework", "AliyunIdentityManager.framework", "APBToygerFacade.framework", "APPSecuritySDK.framework", "BioAuthAPI.framework", "BioAuthEngine.framework", "MPRemoteLogging.framework", "OCRDetectSDKForTech.framework", "ToygerService.framework", "ZolozIdentityManager.framework", "ZolozMobileRPC.framework", "ZolozOpenPlatformBuild.framework", "ZolozSensorServices.framework", "ZolozUtility.framework"
  s.resources = "ios/sdk/APBToygerFacade.framework/APBToygerFacade.bundle","ios/sdk/ToygerService.framework/ToygerService.bundle","ios/sdk/BioAuthEngine.framework/BioAuthEngine.bundle","ios/sdk/OCRDetectSDKForTech.framework/OCRXMedia.bundle"
  s.dependency "React-Core"
end
