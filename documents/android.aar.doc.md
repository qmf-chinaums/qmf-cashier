## SDK集成方法（Android aar形式）
aar形式插件提供商户android app集成后，以便接入支付功能。区别于android apk形式的插件，无需安装独立插件apk。  
### 商户app端集成步骤：  
  - [准备事项](#准备事项)
  - [初始化服务](#初始化服务)  
  - [调用服务接口](#调用服务接口)  
  调用接口时，请务必等待上一个接口调用的结果返回之后，再发起下一个接口调用请求，以确保回调正确。  
<h1/>

### 准备事项
- aar形式插件集成时，请将aar demo代码aarLibs与libs目录下的所有依赖包复制到主项目中。

### 初始化服务  
1. 插件接口方法。  

```java
/**
 * SDK接口。
 * 所有接口的方法名都是一样的，以inParams中的参数进行具体接口的区分
 * 参数映射关系，使用方法请参照各个具体接口章节
*/
boolean umspay(Context context, Bundle inParams, IumsPayListener listener);
```

2. 插件回调方法。

```java
package com.chinaums.mpos.aar;

import android.os.Bundle;

public interface IUmsPayListener {
    void onReturnResult(Bundle bundle);
}
```

3. 在调用具体插件接口前，务必进行插件初始化。建议在application中进行初始化。
```java
package com.chinaums.mposdemo.app;

public class MyApplication extends Application {
  /**
   * 构造函数
   */
  public MyApplication() {
    super();
  }

  @Override
  public void onCreate() {
    super.onCreate();
    // ***********************************************************
    // *************在调用插件接口前，首先要初始化插件***************
    // ***********************************************************
    UmsPayManager.getInstance().init(this);

    // ***********************************************************
    // **************注意！！！！！！！！！！！！！！****************
    // ***********************************************************
    // 如果要使用横屏版本，则在AndroidManifest.xml中添加
    // 注意AndroidManifest.xml首先要添加
    // xmlns:tools=http://schemas.android.com/tools

    // 然后添加以下内容
    // <meta-data
    // tools:replace="android:value"
    // android:name="DeviceType"
    // android:value="Pad" >
    // </meta-data>

    // 如果要使用竖屏版本，则在AndroidManifest.xml中添加
    // <meta-data
    // tools:replace="android:value"
    // android:name="DeviceType"
    // android:value="Phone" >
    // </meta-data>      
  }

}
```

### 调用服务接口
> 商户将所有参数按照规范组装成JSON字符串，置于ums_request字段中，  
> 传入umspay方法中。可使用IUmsPayListener来监听接口返回结果(ums_response)。  
> 接口调用方法请参考各接口详细页面。

```java

...省略...
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

// **********************************
// ******* 接口方法 调用示例 *********
// **********************************
UmsPayManager.getInstance().umspay(context, args, new Callback());

...省略...

class Callback extends IUmsPayListener {
    @Override
    public void onReturnResult(final Bundle result) throws RemoteException {
        // 获取结果数据，即获取key为ums_response的值
        // 具体解析内容请参考各接口页面
        String umsResponseJsonStr = result.getString("ums_response");
        ...省略...
    }
}
```
