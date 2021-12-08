# IOS Setup
- 请在 info.plist 配置摄像头权限。

  [![oRraDO.png](https://s4.ax1x.com/2021/12/08/oRraDO.png)](https://imgtu.com/i/oRraDO)

- Bitcode 配置

  [![oRrdbD.png](https://s4.ax1x.com/2021/12/08/oRrdbD.png)](https://imgtu.com/i/oRrdbD)

[comment]: <> (- 添加系统库)

[comment]: <> (  ![添加系统库]&#40;https://intranetproxy.alipay.com/skylark/lark/0/2019/png/127698/1568604710315-3b21d8a7-3e51-4128-9334-f02ea66e6077.png?x-oss-process=image%2Fresize%2Cw_1500&#41;)


- 配置 scheme【如果已经配置可忽略】

  [![oRrBUH.png](https://s4.ax1x.com/2021/12/08/oRrBUH.png)](https://imgtu.com/i/oRrBUH)

  说明：scheme 地址需与 [alipay.user.certify.open.initialize](https://opendocs.alipay.com/open/02ahjy) (身份认证初始化服务) 接口中配置的 return_url 地址一致。


- 配置支付宝的 scheme【如果已经配置可忽略】

  添加 alipays 到 LSApplicationQueriesSchemes
  [![oRr0Ve.png](https://s4.ax1x.com/2021/12/08/oRr0Ve.png)](https://imgtu.com/i/oRr0Ve)

  OR

  在Targets- > info- > Custom iOS Target Properties，或编辑 Info.plist 添加以下内容
  ```xml
    <key>LSApplicationQueriesSchemes</key>
    <array>
      <string>alipays</string><!-- Add this line -->
    </array>
  ```
- ZolozSdk 初始化

  AppDelegate.m 文件
  ``` objc
  #import <ZolozIdentityManager/ZolozSdk.h>
  
  - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
  {
  ...
  // 尽早初始化
  [ZolozSdk init];
  ...
  }
  
  ```
