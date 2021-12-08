package com.reactnativealipayverify;


import android.content.Intent;
import android.net.Uri;

import androidx.annotation.Nullable;

import com.alibaba.fastjson.JSONObject;
import com.alipay.face.utils.StringUtil;
import com.alipay.mobile.android.verify.sdk.ServiceFactory;
import com.alipay.mobile.android.verify.sdk.interfaces.ICallback;
import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.BaseActivityEventListener;
import com.facebook.react.bridge.LifecycleEventListener;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;

import java.util.Map;

/**
 * 支付宝 实名认证
 * Created by Deng Xiang Hong on 2021/04/19.
 */
public class AlipayVerifyModule extends ReactContextBaseJavaModule implements LifecycleEventListener {

  private final ReactApplicationContext reactContext;

  private final ActivityEventListener mActivityEventListener = new BaseActivityEventListener() {
    @Override
    public void onNewIntent(Intent intent) {
      queryCertifyResult(true, intent);
    }
  };

  /**
   * 查询认证结果事件
   */
  private final String EVENT_QUERY_CERTIFY_RESULT = "EVENT_QUERY_CERTIFY_RESULT";
  /**
   * 认证ID
   */
  private String certifyId;

  /**
   * 认证场景码
   */
  private String bizCode;

  /**
   * 等待结果
   */
  private boolean waitForResult = false;


  public AlipayVerifyModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
    reactContext.addLifecycleEventListener(this);
    reactContext.addActivityEventListener(mActivityEventListener);
  }


  @Override
  public String getName() {
    return "AlipayVerify";
  }

  /**
   * 获取认证场景码
   *
   * @param promise Promise
   */
  @ReactMethod
  public void getBizCode(Promise promise) {
    try {
      bizCode = ServiceFactory.build().getBizCode(getCurrentActivity());
      promise.resolve(bizCode);
    } catch (Exception e) {
      promise.reject("Error", e.getMessage());
    }
  }

  /**
   * 验证
   *
   * @param certifyId  认证Id
   * @param certifyUrl 认证链接
   */
  @ReactMethod
  public void verify(String certifyId, String certifyUrl, final Promise promise) {
    if (StringUtil.isNullorEmpty(certifyId) || StringUtil.isNullorEmpty(certifyUrl)) {
      promise.reject("ParamsNull", "参数不存在");
      return;
    }
    try {
      this.certifyId = certifyId;
      // 封装认证数据
      JSONObject requestInfo = new JSONObject();
      requestInfo.put("url", certifyUrl);
      requestInfo.put("certifyId", certifyId);
      requestInfo.put("bizCode", bizCode);
      // 发起认证
      ServiceFactory.build().startService(getCurrentActivity(), requestInfo, new ICallback() {
        @Override
        public void onResponse(Map<String, String> response) {
          String responseCode = response.get("resultStatus");
          if ("9001".equals(responseCode)) {
            // 9001需要等待回调/回前台查询认证结果
            waitForResult = true;
          }
          promise.resolve(responseCode);
        }
      });
    } catch (Exception e) {
      promise.reject("Error", e.getMessage());
    }
  }

  /**
   * 处理回到前台时触发结果查询
   */
  @Override
  public void onHostResume() {
    if (waitForResult) {
      // 查询认证结果
      waitForResult = false;
      queryCertifyResult(false, null);
    }
  }

  @Override
  public void onHostPause() {

  }

  @Override
  public void onHostDestroy() {

  }

  /**
   * 业务方查询结果
   *
   * @param intent           Intent
   * @param isSchemaCallback 是否为schema调用
   */
  protected void queryCertifyResult(boolean isSchemaCallback, @Nullable Intent intent) {
    // 发送监听标记
    boolean isSendEvent;
    if (isSchemaCallback) {
      if (intent == null) {
        return;
      }
      Uri data = intent.getData();
      if (data == null) {
        return;
      }
      // 如果有很多场景会通过schema调用到当前页面，建议在传给认证回跳的schema中，增加参数识别出需要查询认证结果的场景
      String param = data.getQueryParameter("queryResult");
      isSendEvent = "true".equals(param);
    } else {
      isSendEvent = true;
    }

    if (isSendEvent) {
      // 查询认证结果 防止走到onresume中再次查询结果
      waitForResult = false;
      WritableMap params = Arguments.createMap();
      params.putString("certifyId", this.certifyId);
      // 通知RN前台查询认证结果
      this.sendEvent(this.reactContext, EVENT_QUERY_CERTIFY_RESULT, params);
    }
  }

  /**
   * 发送事件
   *
   * @param reactContext reactContext
   * @param eventName    事件名
   * @param params       参数
   */
  private void sendEvent(ReactContext reactContext,
                         String eventName,
                         @Nullable WritableMap params) {
    reactContext
      .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
      .emit(eventName, params);
  }
}
