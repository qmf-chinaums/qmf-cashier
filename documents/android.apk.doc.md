## SDK集成方法（Android apk形式）
apk形式插件提供<font color=#0099ff size=5 face="黑体">AIDL</font>跨进程接口于商户app进行调用。区别于android aar形式的插件，需要安装插件apk。
### 商户app端集成步骤：  
  - [准备事项](#准备事项)
  - [绑定服务](#绑定服务)  
  - [调用服务接口](#调用服务接口)  
  调用接口时，请务必等待上一个接口调用的结果返回之后，再发起下一个接口调用请求，以确保回调正确。  
<h1/>

### 准备事项
- apk形式插件集成时，请先安装插件apk。
- 横屏版 与 竖屏版 的apk是不同的！

### 绑定服务  
1. aidl接口文档([IUmsMposService.aidl](../code/android/apktype/useful/com/chinaums/mpos/service/IUmsMposService.aidl))。必须保持一致。  
以下接口除```int umspay(in Bundle args, in IUmsMposResultListener listener)```都已经废弃，仅可使用umspay方法。
```Java
package com.chinaums.mpos.service;

import android.os.Bundle;
import com.chinaums.mpos.service.IUmsMposResultListener;

interface IUmsMposService {
  void setDevice(in Bundle args, in IUmsMposResultListener listener);
  void bookOrder(in Bundle args, in IUmsMposResultListener listener);
  void payOrder(in Bundle args, in IUmsMposResultListener listener);
  void showTransactionInfoAndSign(in Bundle args, in IUmsMposResultListener listener);
  void queryOrderInfo(in Bundle args, in IUmsMposResultListener listener);
  void cancelTransaction(in Bundle args, in IUmsMposResultListener listener);
  void returnGoods(in Bundle args, in IUmsMposResultListener listener);
  void printBill(in Bundle args, in IUmsMposResultListener listener);
  void checkVersionUpdate(in Bundle args, in IUmsMposResultListener listener);
  void getDeviceId(in Bundle args, in IUmsMposResultListener listener);
  void pay(in Bundle args, in IUmsMposResultListener listener);
  void preAuth(in Bundle args, in IUmsMposResultListener listener);
  void preAuthFin(in Bundle args, in IUmsMposResultListener listener);
  void PreAuthCancel(in Bundle args, in IUmsMposResultListener listener);
  void preAuthFinCancel(in Bundle args, in IUmsMposResultListener listener);
  void checkCurrentEnv(in Bundle args, in IUmsMposResultListener listener);
  void getCardNum(in Bundle args, in IUmsMposResultListener listener);
  void refund(in Bundle args, in IUmsMposResultListener listener);
  int umspay(in Bundle args, in IUmsMposResultListener listener);
}
```

2. 回调接口文档([IUmsMposResultListener.aidl](../code/android/apktype/useful/com/chinaums/mpos/service/IUmsMposResultListener.aidl))必须保持一致。  

```java
package com.chinaums.mpos.service;

oneway interface IUmsMposResultListener {
  void umsServiceResult(in Bundle result);
}
```

3. 绑定AIDL服务。  
> 使用本插件接口前，首先商户app要绑定aidl service。建议在application中初始化绑定。可参考以下代码进行绑定，但以下代码仅仅是绑定方法之一，可自行优化并实现。   

```java
private IUmsMposService mposAidlService;

private ServiceConnection mConnection = new ServiceConnection() {
  public void onServiceConnected(ComponentName className, IBinder service) {
    mposAidlService = IUmsMposService.Stub.asInterface(service);
  }

  public void onServiceDisconnected(ComponentName className) {
      mposAidlService = null;
  }      
};

/**
 * 竖屏版本插件的绑定
 */
private void bindUmsMposServiceForPhone() {
    Intent intent = new Intent();
    // ******请注意 横屏版 与 竖屏版 的classname有区别！！
    intent.setClassName("com.chinaums.mposplugin", "com.chinaums.mpos.service.MposService");
    bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
}

/**
 * 横屏版本插件的绑定
 */
private void bindUmsMposServiceForPad() {
    Intent intent = new Intent();
    // ******请注意 横屏版 与 竖屏版 的classname有区别！！
    intent.setClassName("com.chinaums.mpospluginpad", "com.chinaums.mpos.service.MposService");
    bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
}

/**
 * 解绑服务
 */
private void unbindUmsMposService() {
    unbindService(mConnection);
}
```

### 调用服务接口  
> 商户将所有参数按照规范组装成JSON字符串，置于ums_request字段中；  
> 将ums_request传入umspay方法中；
> 使用IUmsMposResultListener.Stub来监听接口返回结果，查看其中的ums_response字段。  
> 接口调用方法请参考各接口页面。

```java
Bundle bundle = new Bundle();

// 设置请求参数，jsonString内容参考各接口页面
// jsonString如以下形式的json字符串：
// {
//     "business_id": "ums.trade.query.order.x4o1jmkb",
//     "data": {
//         "billsMID": "shouji000000004",
//         "billsTID": "sj000004",
//         "orderId": "642017062300254415",
//         "merOrderId": ""
//     },
//     "extend_params": {
// 
//     }
// }
bundle.putString("ums_request", jsonString);

try {
    // **********************************
    // ******* 接口方法 调用示例 *********
    // **********************************
    mposAidlService.umspay(bundle, new Callback());
} catch(RemoteException e) {
    e.printStackTrace();
}

...省略...

class Callback extends IUmsMposResultListener.Stub {
    @Override
    public void umsServiceResult(final Bundle result) throws RemoteException {
        // 获取结果数据，即获取key为ums_response的值
        // 具体解析内容请参考各接口页面
        String umsResponseJsonStr = result.getString("ums_response");
        ...省略...
    }
}
```
