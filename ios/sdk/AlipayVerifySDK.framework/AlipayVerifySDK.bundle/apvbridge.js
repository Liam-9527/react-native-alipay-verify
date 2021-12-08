'use strict';

var _typeof = typeof Symbol === "function" && typeof Symbol.iterator === "symbol" ? function (obj) { return typeof obj; } : function (obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; };

window.APVJSBridge || function () {
  var pool = {};
  window.APVJSBridge = {
    /**
     * 璋冪敤native 鏂规硶
     * @param {*} action 鏂规硶鍚�
     * @param {*} data 鍙傛暟
     * @param {*} callback 鍥炶皟鏂规硶
     */
    call: function call(action, data, callback) {
      if (typeof action !== 'string') {
        return;
      }

      if (typeof data === 'function') {
        callback = data;
        data = null;
      } else if ((typeof data === 'undefined' ? 'undefined' : _typeof(data)) !== 'object') {
        data = null;
      }

      var eventId = '' + new Date().getTime() + Math.random();
      if (typeof callback === 'function') {
        pool[eventId] = callback;
      }

      var msg = JSON.stringify({
        action: action,
        data: data,
        eventId: eventId
      });
      // console.log(`bridge.log.message: ${msg}`);
      this.iframeCall(msg);
    },
    iframeCall: function iframeCall(paramStr) {
      var iframe = document.createElement('iframe');
      iframe.style.width = '1px';
      iframe.style.height = '1px';
      iframe.style.display = 'none';
      iframe.src = 'apvbridge://callNativeFunc?' + paramStr;
      var parent = document.body || document.documentElement;
      parent.appendChild(iframe);
      setTimeout(function () {
        parent.removeChild(iframe);
      }, 0);
    },
    callback: function callback(response) {
      var _ref = response || {},
          eventId = _ref.eventId,
          data = _ref.data;

      var func = pool[eventId];
      delete pool[eventId];

      if (typeof func === 'function') {
        setTimeout(function () {
          func(data);
        }, 1);
      }
    }
  };

  // 閫氱煡JS 宸茬粡鑾峰緱浜哹ridge
  var readyEvent = document.createEvent('Events');
  readyEvent.initEvent('APVJSBridgeReady', 0, 0);
  var addEventListenerMethod = document.addEventListener;
  document.addEventListener = function (eventType, callback) {
    for (var _len = arguments.length, args = Array(_len > 2 ? _len - 2 : 0), _key = 2; _key < _len; _key++) {
      args[_key - 2] = arguments[_key];
    }

    if (eventType === readyEvent.type) {
      setTimeout(function () {
        callback(readyEvent);
      }, 1);
    }
    addEventListenerMethod.call(document, eventType, callback, args);
  };
  document.dispatchEvent(readyEvent);
}();
