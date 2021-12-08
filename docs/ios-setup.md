# IOS Setup
- 请在 info.plist 配置摄像头权限。

  ![摄像头权限](https://intranetproxy.alipay.com/skylark/lark/0/2018/png/127698/1545882074426-a619bd34-600c-4543-898d-7a4d62994205.png?x-oss-process=image%2Fresize%2Cw_738)


- Bitcode 配置

  ![Bitcode 配置](https://intranetproxy.alipay.com/skylark/lark/0/2019/png/127698/1548667642311-e7ea55fb-5edd-4815-9b0f-dc10dabcf7cc.png?x-oss-process=image%2Fresize%2Cw_738)


[comment]: <> (- 添加系统库)

[comment]: <> (  ![添加系统库]&#40;https://intranetproxy.alipay.com/skylark/lark/0/2019/png/127698/1568604710315-3b21d8a7-3e51-4128-9334-f02ea66e6077.png?x-oss-process=image%2Fresize%2Cw_1500&#41;)


- 配置 scheme【如果已经配置可忽略】

  ![配置 scheme](https://intranetproxy.alipay.com/skylark/lark/0/2020/png/1347/1592448422576-0bb8e7ce-573a-4058-9f04-adecdf7f7db6.png?x-oss-process=image%2Fresize%2Cw_1500)

  说明：scheme 地址需与 [alipay.user.certify.open.initialize](https://opendocs.alipay.com/open/02ahjy) (身份认证初始化服务) 接口中配置的 return_url 地址一致。


- 配置支付宝的 scheme【如果已经配置可忽略】

  添加 alipays 到 LSApplicationQueriesSchemes
  ![添加 alipays ](https://intranetproxy.alipay.com/skylark/lark/0/2020/png/1347/1592448496440-1168e00b-3600-4c29-8c91-490559fe7b8b.png?x-oss-process=image%2Fresize%2Cw_1500)

  OR

  在Targets- > info- > Custom iOS Target Properties，或编辑 Info.plist 添加以下内容
  ```xml
    <key>LSApplicationQueriesSchemes</key>
    <array>
      <string>alipays</string><!-- Add this line -->
    </array>
  ```
- ZolozSdk 初始化，回调处理

  AppDelegate.m 文件
  ``` objc
  #import "AlipayVerify.h"
  #import <ZolozIdentityManager/ZolozSdk.h>
  
  - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
  {
  ...
  // 处理回调
  [AlipayVerify handleCallbackLaunchOptions:launchOptions];
  // 尽早初始化
  [ZolozSdk init];
  ...
  }
  
  
  - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options
  {
  // 处理回调
  [AlipayVerify handleCallback:url];
  return YES;
  }
  ```
