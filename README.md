# react-native-alipay-verify
[![NPM Version](https://img.shields.io/npm/v/react-native-alipay-verify.svg)](https://npmjs.org/package/react-native-alipay-verify)
[![Dependency Status](https://img.shields.io/david/react-native-alipay-verify.svg)](https://david-dm.org/react-native-alipay-verify)
[![Build Status](https://img.shields.io/travis/react-native-alipay-verify/master.svg)](https://travis-ci.org/react-native-alipay-verify)
[![License](https://img.shields.io/npm/l/react-native-alipay-verify.svg)](./LICENSE)

🍺🍺🍺 支付宝实名认证（人脸识别，生物识别）,移动端调起实名认证流程进行了封装 📦 ， 真实姓名+身份证号+人脸识别

身份验证官方文档：https://opendocs.alipay.com/open/20181012100420932508/intro

**在使用前确保你已完成了服务端的接入工作，组件完成了移动端接入**

(x) 服务端SDK接入流程：https://opendocs.alipay.com/open/20181012100420932508/01brh4 （需手动接入）

(√) ~~Adnroid 客户端接入流程：https://opendocs.alipay.com/open/20181012100420932508/00zc1e~~

(√) ~~iOS 客户端接入流程：https://opendocs.alipay.com/open/20181012100420932508/00ze52~~
****

[![o6LKnH.png](https://s4.ax1x.com/2021/12/07/o6LKnH.png)](https://imgtu.com/i/o6LKnH)

# Requirement
- React Native >= 0.60.0
- iOS >= 9.0
- Android >= 4.4

    
SDK library :

- iOS: v2.1.1
- Android: v2.0.0

# Installation

```sh
npm install react-native-alipay-verify
```

or

```sh
yarn add react-native-alipay-verify
```

IOS 需要手动处理额外的步骤 ➡️ [IOS Setup](./docs/ios-setup.md)

# Usage

```js
import AlipayVerify, {ResultStatusCode, AlipayVerifyEvent} from "react-native-alipay-verify";

// 获取场景码
AlipayVerify.getBizCode().then((bizCode) => {
	console.log(bizCode)
}).catch((error) => console.log(error));

// 发起人脸识别认证
AlipayVerify.verify(verifyData.certifyId, verifyData.certifyUrl).then((verifyResult) => {
      let message = ""
      switch (Number(verifyResult)) {
        case ResultStatusCode.NETWORK_ANOMALY: message = '网络异常';
          break;
        case ResultStatusCode.SYSTEM_EXCEPTION: message = '系统异常';
          break;
        case ResultStatusCode.USER_CANCEL: message = '用户取消认证';
          break;
        case ResultStatusCode.VERIFY_SUCCESS:
          // 向认证服务器 证实 认证结果
          break;
        case ResultStatusCode.AWAIT_VERIFY:
          // 等待认证结果， 通过监听方式得到认证结束通知
          
          break;
        default:
          message = "调起支付宝SDK失败，错误码："+ verifyResult
          break;
      }
      console.log(message+ " " + verifyResult);
}).catch((error) => console.log(error));

// 监听回调 此处为认证结束的事件。认证成功与否需要前往服务器验证
DeviceEventEmitter.addListener(AlipayVerifyEvent.EVENT_QUERY_CERTIFY_RESULT,(event) => {
      console.log("监听："+ JSON.stringify(event));
      // 向商户服务器 证实 认证结果
})

// 防止错过认证结束通知 回到前台时处理 认证状态
AppState.addEventListener('change', (appState) => {
  if(appState === 'active'){
    // 向商户服务器 证实 认证结果
  }
});
```

# TODO

- ~~iOS设备下，场景码获取始终为 FACE_ALIPAY_SDK~~
- iOS设备下，下没有安装支付宝APP时无法调起内置SDK进行识别

# License

MIT

