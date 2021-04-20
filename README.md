# react-native-alipay-verify

react-native-alipay-verify 支付宝实名认证（人脸识别，生物识别）

支付宝官方文档：https://opendocs.alipay.com/open/20181012100420932508/intro

## Installation

```sh
npm install react-native-alipay-verify
```

or

```sh
yarn add react-native-alipay-verify
```

## Usage

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
      }
      console.log(message+ " " + verifyResult);
}).catch((error) => console.log(error));

// 监听异步认证结果
DeviceEventEmitter.addListener(AlipayVerifyEvent.EVENT_QUERY_CERTIFY_RESULT,(event) => {
      console.log("监听："+ JSON.stringify(event));
      // 向认证服务器 证实 认证结果
    
})
```

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## TODO

- IOS 下场景码获取异常始终为 FACE_ALIPAY_SDK
- IOS 下没有安装支付宝时无法调起内置SDK进行识别

## License

MIT

