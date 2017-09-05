## 补发签购单接口
由于各种原因首次交易流程中，未能获取到签购单。或者，希望再次获取某一交易的签购单。这时可以使用本接口重新发行签购单。  
> 当返回main_code=“MC_110001”时，表示业务正常处理完毕。此时data字段下含有业务数据信息。  
> 当返回main_code=“MC_310001”或“MC_310002”时，表示补发签购单发生异常，请核对错误信息后，重新调用本接口。  
> 当返回main_code=“MC_210001”时，表示请求超时，网络断连等。  
<h1></h1>

### 1. 代码调用示例

```objc
#import "UMSCashierPlugin.h"
@implementation UseSDKViewController<UMSCashierPluginDelegate>

// iOS Delegate方法名。
// dict为最新版本返回参数，其它已作废。dict含有ums_response字段。
-(void)onUMSSignOrder:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus ResultInfo:(NSDictionary *)resultInfo;

...省略...

- (void)doWork
{
  // iOS sdk集成示例
  NSDictionary *paramDic = [[NSDictionary alloc] init];
  paramDic[@"ums_request"] = jsonString;
  [UMSCashierPlugin umsSignOrder:paramDic ViewController:self Delegate:self];
}
```
```java
// Android APK集成示例
Bundle bundle = new Bundle();
// 设置请求参数
bundle.putString("ums_request", jsonString);
// callbackFunc为回调方法，会返回ums_response字段
mposAidlService.umspay(bundle, callbackFunc);
```
```java
// Android sdk集成示例
UmsPayManager umsPayManager = UmsPayManager.getInstance();
Bundle bundle = new Bundle();
// callbackFunc为回调方法，会返回ums_response字段
bundle.putString("ums_request", jsonString);
umsPayManager.umspay(context, bundle, callbackFunc);
```

### 2. 接口参数解释
```json
// 请求参数 (ums_request)
{
    "business_id": "ums.trade.resupply.voucher.57pxfv4r",
    "data": {
        "billsMID": "shouji000000004",
        "billsTID": "sj000004",
        "orderId": "642017062300254372",
        "isShowEVoucherPage": "true",
        "saleSlipFavorite": ""
    },
    "extend_params": {

    }
}
```
  
<a href="#must">是否必填：●表示必填    ▲表示有条件必填     ○表示非必填</a>
<table style="text-align:left;">
    <tr>
        <th rowspan="1">序号</th>
        <th>参数一层</th>
        <th>参数二层</th>
        <th>必填</th>
        <th>取值范围</th>
        <th>默认值</th>
        <th>说明</th>
    </tr>
    <tr>
        <th rowspan="2">01</th>
        <th align="left" colspan="6">接口标识</th>
    </tr>
    <tr>
        <td>business_id</td>
        <td>-</td>
        <td>●</td>
        <td>固定ums.trade.resupply.v<br>oucher.57pxfv4r</td>
        <td>-</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="2">02</th>
        <th align="left" colspan="6">请求参数主体</th>
    </tr>
    <tr>
        <td>data</td>
        <td>-</td>
        <td>●</td>
        <td>-</td>
        <td>-</td>
        <td>请求参数主体的key</td>
    </tr>
    <tr>
        <th rowspan="2">03</th>
        <th align="left" colspan="6">商户号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>billsMID</td>
        <td>●</td>
        <td>长度为15位</td>
        <td>-</td>
        <td>银商分公司提供</td>
    </tr>
    <tr>
        <th rowspan="2">04</th>
        <th align="left" colspan="6">终端号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>billsTID</td>
        <td>●</td>
        <td>长度为8位</td>
        <td>-</td>
        <td>银商分公司提供</td>
    </tr>
    <tr>
        <th rowspan="2">05</th>
        <th align="left" colspan="6">原交易的银商订单号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>orderId</td>
        <td>●</td>
        <td>长度为18位</td>
        <td>-</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="2">06</th>
        <th align="left" colspan="6">是否展示电子签购单页面</th>
    </tr>
    <tr>
        <td>-</td>
        <td>isShowEVoucherPage</td>
        <td>○</td>
        <td>字符串"true","false"</td>
        <td>"true"</td>
        <td>是否展示电子签购单页面。<br>◆"true": 展示<br>◆"false"：不展示</td>
    </tr>
    <tr>
        <th rowspan="2">07</th>
        <th align="left" colspan="6">签购单处理方式</th>
    </tr>
    <tr>
        <td>-</td>
        <td>saleSlipFavorite</td>
        <td>○</td>
        <td>paperType、<br>electricType、<br>defaultType</td>
        <td>"defaultType"</td>
        <td>签购单处理方式<br>◆"paperType"：自动打印纸质签购单<br>◆"electricType"：自动发送短信签购单（需求填写消费者手机号）<br>◆"defaultType"：默认方式，即需要手动选择签购单出来方式</td>
    </tr>
    <tr>
        <th rowspan="2">08</th>
        <th align="left" colspan="6">扩展请求参数</th>
    </tr>
    <tr>
        <td>extend_params</td>
        <td>-</td>
        <td>○</td>
        <td>-</td>
        <td>-</td>
        <td>扩展字段的key。内容需要定制化开发。</td>
    </tr>
</table>

```json
// 返回参数 (ums_response)
{
    "business_id": "ums.trade.resupply.voucher.57pxfv4r",
    "main_code": "MC_110001",
    "main_msg": "接口调用成功",
    "sub_code": "SC_100112",
    "sub_code_platform": "03",
    "sub_msg": "发送短信签购单成功，免签名。",
    "data": {
        "deviceId": ""
    },
    "extra": {

    }
}
```
<table>
    <tr>
        <th rowspan="1">序号</th>
        <th>参数一层</th>
        <th>参数二层</th>
        <th>参数名称</th>
        <th>说明</th>
    </tr>
    <tr>
        <th rowspan="1">01</th>
        <td>business_id</td>
        <td>-</td>
        <td>接口标识</td>
        <td>固定ums.trade.resupply.voucher.57pxfv4r</td>
    </tr>
    <tr>
        <th rowspan="1">02</th>
        <td>main_code</td>
        <td>-</td>
        <td>主错误码</td>
        <td>详细请参考《<a href="../comment/comment.error.code.doc.md">错误码说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="1">03</th>
        <td>main_msg</td>
        <td>-</td>
        <td>主错误信息</td>
        <td>详细请参考《<a href="../comment/comment.error.code.doc.md">错误码说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="1">04</th>
        <td>sub_code</td>
        <td>-</td>
        <td>次错误码</td>
        <td>详细请参考《<a href="../comment/comment.error.code.doc.md">错误码说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="1">05</th>
        <td>sub_code_platform</td>
        <td>-</td>
        <td>次错误信息平台</td>
        <td>次错误信息平台。</td>
    </tr>
    <tr>
        <th rowspan="1">06</th>
        <td>sub_msg</td>
        <td>-</td>
        <td>次错误信息</td>
        <td>详细请参考《<a href="../comment/comment.error.code.doc.md">错误码说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="1">07</th>
        <td>data</td>
        <td>-</td>
        <td>返回参数主体</td>
        <td>返回参数主体的key。<br>仅当main_code="MC_110001"时，data中有值。</td>
    </tr>
    <tr>
        <th rowspan="1">08</th>
        <td>-</td>
        <td>deviceId</td>
        <td>设备号</td>
        <td>连接设备的设备号，补发电子签购单时填空</td>
    </tr>
</table>
