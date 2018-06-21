## SDK集成方法（iOS）
iOS插件提供商户iOS app集成后，以便接入支付功能。  

### 商户app端集成步骤：  
  - [准备事项](#准备事项)
  - [接口与回调](#接口与回调)  
  - [调用服务接口](#调用服务接口)  
  调用接口时，请务必等待上一个接口调用的结果返回之后，再发起下一个接口调用请求，以确保回调正确。  
<h1/>

### 准备事项
- iOS插件集成时，请将插件包中的.a、.h及bundle资源文件复制到主项目中。
- 主项目需引入libicucore.dylib、Foundation.framework、UIKit.framework、CoreData.framework、libsqlite3.tdb，否则会出现编译错误
- 在主项目设置项，修改： 
  - TARGETS -> Build Settings -> Other Linker Flags 添加```-all_load```或```-ObjC```

### 接口与回调
每个具体功能的接口方法与回调方法请参考头文件 [UMSCashierPlugin.h](../code/ios/useful/UMSCashierPlugin.h)

### 调用服务接口
> 商户将所有参数按照规范组装成JSON字符串，置于相应接口方法的ums_request字段中，  
> 在相应回调方法中获取ums_response字段中JSON内容。  
> 接口调用方法请参考各接口详细页面，下面以消费接口为例说明。

  ```ObjC
  #import "UseSDKViewController.h"
  #import "UMSCashierPlugin.h"

  @implementation UseSDKViewController<UMSCashierPluginDelegate>

  - (void)viewDidLoad
  {
      ...省略...
  }

  // 支付按钮事件
  - (void)umsPay
  {
      NSDictionary *paramDic = [[NSDictionary alloc] init];
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
      paramDic[@"ums_request"] = jsonString;

      // **********************************
      // ******* 接口方法 调用示例 *********
      // **********************************
      // 支付接口调用，各个具体接口方法名都是不同的
      // 各接口方法名称，都已记录在各接口页面中。
      // 本例中使用的接口方法名为umsPay
      [UMSCashierPlugin umsPay:dic ViewController:self Delegate:self];

  }

  // 支付回调，各个具体接口方法的delegate方法名都是不同的
  // 各接口的delegate方法名称，都已记录在各接口页面中。
  // 本例中消费delegate方法名为onPayResult
  - (void)onPayResult:(PayStatus)payStatus
  	    PrintStatus:(PrintStatus)printStatus
      SignatureStatus:(SignatureStatus)uploadStatus
  		   withInfo:(NSDictionary *)dict
  {
    // 获取结果数据，即获取key为ums_response的值
    // 具体解析内容请参考各接口页面
    NSString *ums_response = dict[@"ums_response"];
    ...省略...

  }

  @end
  ```
