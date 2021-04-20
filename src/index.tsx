import { NativeModules } from 'react-native';

export enum ResultStatusCode {
  /** 等待支付宝端完成认证。*/
  AWAIT_VERIFY = 9001,
  /** 认证通过 表示当前certifyId已认证通过 无需再次认证，但需向认证服务器查询真实认证结果 */
  VERIFY_SUCCESS = 9000,
  /** 网络异常 */
  NETWORK_ANOMALY = 6002,
  /** 用户取消 */
  USER_CANCEL = 6001,
  /** 系统异常 */
  SYSTEM_EXCEPTION = 4000
}

export enum AlipayVerifyEvent {
  EVENT_QUERY_CERTIFY_RESULT = "EVENT_QUERY_CERTIFY_RESULT"
}

type AlipayVerifyType = {
  /**
   * 获取认证场景码
   * FACE：多因子人脸认证
   * CERT_PHOTO：多因子证照认证
   * CERT_PHOTO_FACE ：多因子证照和人脸认证
   * SMART_FACE：多因子快捷认证
   */
  getBizCode(): Promise<string>,

  /**
   * 核实
   * @param certifyId 认证Id
   * @param certifyUrl 认证url
   */
  verify(certifyId: string, certifyUrl: string): Promise<ResultStatusCode>


};

const { AlipayVerify } = NativeModules;

export default AlipayVerify as AlipayVerifyType;
