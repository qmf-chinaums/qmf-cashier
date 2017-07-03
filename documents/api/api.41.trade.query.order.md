## 交易查询接口
商户可以调用订单查询接口获取已有订单的最新订单状态。对于撤销类交易，包括消费撤销，预授权撤销，预授权完成撤销，在订单查询时，传入的商户订单号需为原交易的商户订单号。  
> 当返回main_code=“MC_110001”时，表示业务正常处理完毕。此时data字段下含有业务数据信息。  
> 当返回main_code=“MC_310001”或“MC_310002”时，表示业务处理发生异常，请核对错误信息后，重新调用本接口。  
> 当返回main_code=“MC_210001”时，表示请求超时，网络断连等。  
<h1></h1>

### 1. 代码调用示例

```objc
#import "UMSCashierPlugin.h"
@implementation UseSDKViewController<UMSCashierPluginDelegate>

// iOS Delegate方法名。
// dict为最新版本返回参数，其它已作废。dict含有ums_response字段。
-(void)onUMSQueryOrder:(NSDictionary *)dict;

...省略...

- (void)doWork
{
  // iOS sdk集成示例
  NSDictionary *paramDic = [[NSDictionary alloc] init];
  paramDic[@"ums_request"] = jsonString;
  [UMSCashierPlugin umsQueryOrder:paramDic Delegate:self];
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
    "business_id": "ums.trade.query.order.x4o1jmkb",
    "data": {
        "billsMID": "shouji000000004",
        "billsTID": "sj000004",
        "orderId": "642017062300254415",
        "merOrderId": ""
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
        <th>参默认值</th>
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
        <td>固定ums.trade.query.order.x4o1jmkb</td>
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
        <td>▲</td>
        <td>长度为18位</td>
        <td>-</td>
        <td>orderId与merOrderId只需要传一个，若传入了orderId则优先使用orderId</td>
    </tr>
    <tr>
        <th rowspan="2">06</th>
        <th align="left" colspan="6">原交易的商户订单号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>merOrderId</td>
        <td>▲</td>
        <td>长度>=11位</td>
        <td>-</td>
        <td>orderId与merOrderId只需要传一个，若传入了orderId则优先使用orderId</td>
    </tr>
    <tr>
        <th rowspan="2">07</th>
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
    "business_id": "ums.trade.query.order.x4o1jmkb",
    "main_code": "MC_110001",
    "main_msg": "接口调用成功",
    "sub_code": "SC_100300",
    "sub_code_platform": "03",
    "sub_msg": "业务处理成功",
    "data": {
        "billsMID": "shouji000000004",
        "billsMercName": "银联商务测试商户",
        "billsTID": "sj000004",
        "deviceId": "00011006150000579442",
        "orderId": "642017062300254415",
        "merOrderId": "1498187528239",
        "amount": "1",
        "transType": "SALE",
        "currencyCode": "156",
        "operator": "000001",
        "cardType": "1",
        "orgId": "",
        "authNo": "",
        "acqNo": "48020000",
        "issNo": "03010000",
        "pAccount": "521899******2081",
        "cardOrgCode": "CUP",
        "issBankName": "某某银行",
        "processCode": "",
        "voucherNo": "058044",
        "voucherDate": "111207",
        "voucherTime": "0623",
        "liqDate": "0623",
        "serviceCode": "",
        "refId": "000110050214",
        "merchantId": "shouji000000004",
        "termId": "sj000004",
        "batchNo": "000002",
        "dealDate": "2017-06-23 11:12:26",
        "payStatus": "1",
        "refersystemid": "000110050214058044",
        "fullPAccount": "",
        "signatureStatus": "2|0"
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
        <td>固定ums.trade.query.order.x4o1jmkb</td>
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
        <td>billsMID</td>
        <td>出账商户号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">09</th>
        <td>-</td>
        <td>billsMercName</td>
        <td>出账商户名</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">10</th>
        <td>-</td>
        <td>billsTID</td>
        <td>出账终端号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">11</th>
        <td>-</td>
        <td>deviceId</td>
        <td>设备号</td>
        <td>交易时的刷卡POS设备号</td>
    </tr>
    <tr>
        <th rowspan="1">12</th>
        <td>-</td>
        <td>orderId</td>
        <td>银行订单号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">13</th>
        <td>-</td>
        <td>merOrderId</td>
        <td>商户订单号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">14</th>
        <td>-</td>
        <td>amount</td>
        <td>消费金额</td>
        <td>单位为分</td>
    </tr>
    <tr>
        <th rowspan="1">15</th>
        <td>-</td>
        <td>transType</td>
        <td>交易类别</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">16</th>
        <td>-</td>
        <td>currencyCode</td>
        <td>交易货币代码</td>
        <td>按照<a href="https://www.iso.org/iso-4217-currency-codes.html">ISO 4217规范</a>返回<br>人民币：156</td>
    </tr>
    <tr>
        <th rowspan="1">17</th>
        <td>-</td>
        <td>operator</td>
        <td>操作员号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">18</th>
        <td>-</td>
        <td>cardType</td>
        <td>卡类型</td>
        <td>借记卡：0<br>贷记卡：1</td>
    </tr>
    <tr>
        <th rowspan="1">19</th>
        <td>-</td>
        <td>orgId</td>
        <td>分支机构</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">20</th>
        <td>-</td>
        <td>authNo</td>
        <td>授权码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">21</th>
        <td>-</td>
        <td>acqNo</td>
        <td>收单机构号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">22</th>
        <td>-</td>
        <td>issNo</td>
        <td>发卡机构号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">23</th>
        <td>-</td>
        <td>pAccount</td>
        <td>卡号（前六后四）</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">24</th>
        <td>-</td>
        <td>cardOrgCode</td>
        <td>卡组织机构代码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">25</th>
        <td>-</td>
        <td>issBankName</td>
        <td>发卡行名称</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">26</th>
        <td>-</td>
        <td>processCode</td>
        <td>交易处理码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">27</th>
        <td>-</td>
        <td>voucherNo</td>
        <td>受卡方系统跟踪号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">28</th>
        <td>-</td>
        <td>voucherDate</td>
        <td>受卡方所在地日期</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">29</th>
        <td>-</td>
        <td>voucherTime</td>
        <td>受卡方所在地时间</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">30</th>
        <td>-</td>
        <td>liqDate</td>
        <td>清算日期</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">31</th>
        <td>-</td>
        <td>serviceCode</td>
        <td>服务点条件码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">32</th>
        <td>-</td>
        <td>refId</td>
        <td>检索参考号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">33</th>
        <td>-</td>
        <td>merchantId</td>
        <td>受卡方标识码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">34</th>
        <td>-</td>
        <td>termId</td>
        <td>受卡机终端标识码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">35</th>
        <td>-</td>
        <td>batchNo</td>
        <td>批次号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">36</th>
        <td>-</td>
        <td>dealDate</td>
        <td>交易时间</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">37</th>
        <td>-</td>
        <td>phoneNumber</td>
        <td>消费者手机号</td>
        <td>若有，则是带星号的手机号</td>
    </tr>
    <tr>
        <th rowspan="1">38</th>
        <td>-</td>
        <td>payStatus</td>
        <td>支付状态</td>
        <td>详细请参考《<a href="../comment/comment.pay.status.doc.md">payStatus说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="1">38</th>
        <td>-</td>
        <td>refersystemid</td>
        <td>系统参考号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">39</th>
        <td>-</td>
        <td>fullPAccount</td>
        <td>全卡号</td>
        <td>仅预授权交易的查询返回</td>
    </tr>
    <tr>
        <th rowspan="1">40</th>
        <td>-</td>
        <td>signatureStatus</td>
        <td>打印状态</td>
        <td>参考《<a href="../comment/comment.signature.status.doc.md">signatureStatus说明</a>》</td>
    </tr>
    <tr>
        <th rowspan="1">41</th>
        <td>extra</td>
        <td>-</td>
        <td>扩展返回参数的key</td>
        <td>-</td>
    </tr>
</table>
