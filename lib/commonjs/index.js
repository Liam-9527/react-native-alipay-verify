"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = exports.AlipayVerifyEvent = exports.ResultStatusCode = void 0;

var _reactNative = require("react-native");

let ResultStatusCode;
exports.ResultStatusCode = ResultStatusCode;

(function (ResultStatusCode) {
  ResultStatusCode[ResultStatusCode["AWAIT_VERIFY"] = 9001] = "AWAIT_VERIFY";
  ResultStatusCode[ResultStatusCode["VERIFY_SUCCESS"] = 9000] = "VERIFY_SUCCESS";
  ResultStatusCode[ResultStatusCode["NETWORK_ANOMALY"] = 6002] = "NETWORK_ANOMALY";
  ResultStatusCode[ResultStatusCode["USER_CANCEL"] = 6001] = "USER_CANCEL";
  ResultStatusCode[ResultStatusCode["SYSTEM_EXCEPTION"] = 4000] = "SYSTEM_EXCEPTION";
})(ResultStatusCode || (exports.ResultStatusCode = ResultStatusCode = {}));

let AlipayVerifyEvent;
exports.AlipayVerifyEvent = AlipayVerifyEvent;

(function (AlipayVerifyEvent) {
  AlipayVerifyEvent["EVENT_QUERY_CERTIFY_RESULT"] = "EVENT_QUERY_CERTIFY_RESULT";
})(AlipayVerifyEvent || (exports.AlipayVerifyEvent = AlipayVerifyEvent = {}));

const {
  AlipayVerify
} = _reactNative.NativeModules;
var _default = AlipayVerify;
exports.default = _default;
//# sourceMappingURL=index.js.map