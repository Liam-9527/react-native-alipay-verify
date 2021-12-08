import { NativeModules } from 'react-native';
export let ResultStatusCode;

(function (ResultStatusCode) {
  ResultStatusCode[ResultStatusCode["AWAIT_VERIFY"] = 9001] = "AWAIT_VERIFY";
  ResultStatusCode[ResultStatusCode["VERIFY_SUCCESS"] = 9000] = "VERIFY_SUCCESS";
  ResultStatusCode[ResultStatusCode["NETWORK_ANOMALY"] = 6002] = "NETWORK_ANOMALY";
  ResultStatusCode[ResultStatusCode["USER_CANCEL"] = 6001] = "USER_CANCEL";
  ResultStatusCode[ResultStatusCode["SYSTEM_EXCEPTION"] = 4000] = "SYSTEM_EXCEPTION";
})(ResultStatusCode || (ResultStatusCode = {}));

export let AlipayVerifyEvent;

(function (AlipayVerifyEvent) {
  AlipayVerifyEvent["EVENT_QUERY_CERTIFY_RESULT"] = "EVENT_QUERY_CERTIFY_RESULT";
})(AlipayVerifyEvent || (AlipayVerifyEvent = {}));

const {
  AlipayVerify
} = NativeModules;
export default AlipayVerify;
//# sourceMappingURL=index.js.map