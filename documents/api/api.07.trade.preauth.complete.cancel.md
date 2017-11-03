## 预授权完成撤销成接口
商户可以调用预授权完成撤销接口来对原预授权完成交易进行撤销操作。  
> 当返回main_code=“MC_110001”时，表示业务正常处理完毕。此时data字段下含有业务数据信息。  
> 当返回main_code=“MC_310001”或“MC_310002”时，表示该笔订单支付状态异常，如果需要重新支付/继续支付，那么要重新调用接口。  
> 当返回main_code=“MC_210001”时，表示请求超时，网络断连等，请调用“订单信息查询”接口获取最终支付结果。  
<h1></h1>

### 1. 代码调用示例

```objc
#import "UMSCashierPlugin.h"
@implementation UseSDKViewController<UMSCashierPluginDelegate>

// iOS Delegate方法名。
// dict为最新版本返回参数，其它已作废。dict含有ums_response字段。
-(void)onUMSPreAuth:(PreAuthType)preAuthType TransactionStatus:(TransactionStatus)transactionStatus PrintStatus:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus withInfo:(NSDictionary *)dict;

...省略...

- (void)doWork
{
  // iOS sdk集成示例
  NSDictionary *paramDic = [[NSDictionary alloc] init];
  paramDic[@"ums_request"] = jsonString;
  [UMSCashierPlugin  umsPreAuthFinCancel:dic ViewController:self Delegate:self];
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
    "business_id": "ums.trade.preauth.complete.cancel.z2nhgt43",
    "data": {
        "billsMID": "shouji000000004",
        "billsTID": "sj000004",
        "operator": "000001",
        "originOrderId": "752017062200254322",
        "originAuthNo": "024846",
        "originMerOrderId": "",
        "isUseBankcard": "false",
        "memo": "指定格式的备注字段"
    },
    "extend_params": {

    },
    "sign": "slRpHqJIl8fT0JoBpJsnMhDPzR5++/hw9EUnd8BGtT4ifBlGb0H88aPRnTiqhT5/JKiPklUGYl1pSmAjEVAdKSErTwiIHkZdLFR+yuUCFU1X6uL6VTs3DAGhgpvQ6SY1qbUcGpwXrICtpLWlSA3rZ4W7meFS4cLvCg1hgEUIcmM="
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
        <td>固定ums.trade.preauth.co<br>mplete.cancel.z2nhgt43</td>
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
        <th align="left" colspan="6">原预授权完成商户订单号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>originMerOrderId</td>
        <td>▲</td>
        <td>长度>=11位且<=64位</td>
        <td>-</td>
        <td>originOrderId与originMerOrderId只需要传一个，<br>若传入了originOrderId则优先使用originOrderId</td>
    </tr>
    <tr>
        <th rowspan="2">06</th>
        <th align="left" colspan="6">原预授权完成银商订单号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>originOrderId</td>
        <td>▲</td>
        <td>长度为18位</td>
        <td>-</td>
        <td>originOrderId与originMerOrderId只需要传一个，<br>若传入了originOrderId则优先使用originOrderId</td>
    </tr>
    <tr>
        <th rowspan="2">07</th>
        <th align="left" colspan="6">原预授权完成返回的授权码</th>
    </tr>
    <tr>
        <td>-</td>
        <td>originAuthNo</td>
        <td>●</td>
        <td>长度小于等于200位</td>
        <td>-</td>
        <td>原预授权完成返回的授权码</td>
    </tr>
    <tr>
        <th rowspan="2">08</th>
        <th align="left" colspan="6">是否使用银行卡交易</th>
    </tr>
    <tr>
        <td>-</td>
        <td>isUseBankcard</td>
        <td>○</td>
        <td>字符串"true","false"</td>
        <td>"false"</td>
        <td>是否使用银行卡交易<br>◆"true": 必须使用银行卡<br>◆"false"：不需要使用银行卡</td>
    </tr>
    <tr>
        <th rowspan="2">09</th>
        <th align="left" colspan="6">操作员号</th>
    </tr>
    <tr>
        <td>-</td>
        <td>operator</td>
        <td>○</td>
        <td>长度小于等于12位</td>
        <td>-</td>
        <td>操作员号<br></td>
    </tr>
    <tr>
        <th rowspan="2">10</th>
        <th align="left" colspan="6">备注</th>
    </tr>
    <tr>
        <td>-</td>
        <td>memo</td>
        <td>○</td>
        <td>长度小于等于256位</td>
        <td>-</td>
        <td>指定格式的备注字段<br>◆详细请参考《<a href="../comment/comment.memo.doc.md">备注字段说明</a>》章节</td>
    </tr>
    <tr>
        <th rowspan="2">11</th>
        <th align="left" colspan="6">扩展请求参数</th>
    </tr>
    <tr>
        <td>extend_params</td>
        <td>-</td>
        <td>○</td>
        <td>-</td>
        <td>-</td>
        <td>扩展字段的key。<br>内容需要定制化开发。</td>
    </tr>
    <tr>
        <th rowspan="2">12</th>
        <th align="left" colspan="6">加签后的签名内容</th>
    </tr>
    <tr>
        <td>sign</td>
        <td>-</td>
        <td>●</td>
        <td>-</td>
        <td>-</td>
        <td>调用方使用规定的<a href="../comment/comment.sign.doc.md">加签算法</a>，<br>对data中的字段进行加签后的签名内容</td>
    </tr>
</table>

```json
// 返回参数 (ums_response)
{
    "business_id": "ums.trade.preauth.complete.cancel.z2nhgt43",
    "main_code": "MC_110001",
    "main_msg": "接口调用成功",
    "sub_code": "SC_100105",
    "sub_code_platform": "03",
    "sub_msg": "打印纸质签购单成功。",
    "data": {
        "billsMID": "shouji000000004",
        "billsMercName": "银联商户测试商户",
        "billsTID": "sj000004",
        "deviceId": "00011006200000579432",
        "orderId": "752017062200254322",
        "merOrderId": "1498126924348",
        "amount": "1",
        "currencyCode": "156",
        "operator": "000001",
        "cardType": "1",
        "orgId": "",
        "authNo": "024846",
        "acqNo": "48020000",
        "issNo": "03010000",
        "pAccount": "521899******2081",
        "cardOrgCode": "CUP",
        "issBankName": "某某银行",
        "processCode": "",
        "voucherNo": "058032",
        "voucherDate": "0622",
        "voucherTime": "182506",
        "liqDate": "0622",
        "serviceCode": "",
        "refId": "000110047225",
        "merchantId": "shouji000000004",
        "termId": "sj000004",
        "batchNo": "000002",
        "dealDate": "2017-06-22 18:25:25",
        "phoneNumber": "123****8901"
    },
    "extra": {

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
        <td>预授权完成撤销<br>固定ums.trade.preauth.complete.cancel.z2nhgt43</td>
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
        <td>currencyCode</td>
        <td>交易货币代码</td>
        <td>按照<a href="https://www.iso.org/iso-4217-currency-codes.html">ISO 4217规范</a>返回<br>人民币：156</td>
    </tr>
    <tr>
        <th rowspan="1">16</th>
        <td>-</td>
        <td>operator</td>
        <td>操作员号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">17</th>
        <td>-</td>
        <td>cardType</td>
        <td>卡类型</td>
        <td>借记卡：0<br>贷记卡：1</td>
    </tr>
    <tr>
        <th rowspan="1">18</th>
        <td>-</td>
        <td>orgId</td>
        <td>分支机构</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">19</th>
        <td>-</td>
        <td>authNo</td>
        <td>授权码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">20</th>
        <td>-</td>
        <td>acqNo</td>
        <td>收单机构号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">21</th>
        <td>-</td>
        <td>issNo</td>
        <td>发卡机构号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">22</th>
        <td>-</td>
        <td>pAccount</td>
        <td>卡号（前六后四）</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">23</th>
        <td>-</td>
        <td>cardOrgCode</td>
        <td>卡组织机构代码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">24</th>
        <td>-</td>
        <td>issBankName</td>
        <td>发卡行名称</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">25</th>
        <td>-</td>
        <td>processCode</td>
        <td>交易处理码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">26</th>
        <td>-</td>
        <td>voucherNo</td>
        <td>受卡方系统跟踪号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">27</th>
        <td>-</td>
        <td>voucherDate</td>
        <td>受卡方所在地日期</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">28</th>
        <td>-</td>
        <td>voucherTime</td>
        <td>受卡方所在地时间</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">29</th>
        <td>-</td>
        <td>liqDate</td>
        <td>清算日期</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">30</th>
        <td>-</td>
        <td>serviceCode</td>
        <td>服务点条件码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">31</th>
        <td>-</td>
        <td>refId</td>
        <td>检索参考号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">32</th>
        <td>-</td>
        <td>merchantId</td>
        <td>受卡方标识码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">33</th>
        <td>-</td>
        <td>termId</td>
        <td>受卡机终端标识码</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">34</th>
        <td>-</td>
        <td>batchNo</td>
        <td>批次号</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">35</th>
        <td>-</td>
        <td>dealDate</td>
        <td>交易时间</td>
        <td>-</td>
    </tr>
    <tr>
        <th rowspan="1">36</th>
        <td>-</td>
        <td>phoneNumber</td>
        <td>消费者手机号</td>
        <td>若有，则是带星号的手机号</td>
    </tr>
    <tr>
        <th rowspan="1">37</th>
        <td>extra</td>
        <td>-</td>
        <td>扩展返回参数的key</td>
        <td>-</td>
    </tr>
</table>
