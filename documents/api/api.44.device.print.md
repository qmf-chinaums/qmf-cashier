## 打印小票接口
本接口提供给商户自行打印销售单据，打印内容和格式由商户定义好传进来。这个销售单据打印一次算打印成功。打印规范参见《<a href="../attachment/银商移动刷卡终端打印规范_20140604_V1.2.pdf">银商移动刷卡终端打印规范</a>》。  
> 当返回main_code=“MC_110001”时，表示业务正常处理完毕。此时data字段下含有业务数据信息。  
> 当返回main_code=“MC_310001”或“MC_310002”时，表示打印发生异常，请核对错误信息后，重新调用本接口。  
> 当返回main_code=“MC_210001”时，表示请求超时，网络断连等。  
<h1></h1>

### 1. 代码调用示例

```objc
#import "UMSCashierPlugin.h"
@implementation UseSDKViewController<UMSCashierPluginDelegate>

// iOS Delegate方法名。
// dict为最新版本返回参数，其它已作废。dict含有ums_response字段。
-(void)onUMSPrint:(PaperResult) status resultInfo:(NSDictionary *)resultInfo;

...省略...

- (void)doWork
{
  // iOS sdk集成示例
  NSDictionary *paramDic = [[NSDictionary alloc] init];
  paramDic[@"ums_request"] = jsonString;
  [UMSCashierPlugin umsPrint:paramDic ViewController:self Delegate:self];
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
    "business_id": "ums.device.print.cpuhqbfa",
    "data":
    {
        "billsMID": "shouji000000004",
        "billsTID": "sj000004",
        "message": "!hz l\r\n!asc l\r\n!gray 10 \r\n*text c 外卖单\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text c (1号)\r\n*line \r\n!hz l\r\n!asc l\r\n*text l 商家配送:              商家配送\r\n!hz l\r\n!asc l\r\n*text l 备注:                    xmxxkk\r\n*feedline 1\r\n*line 1 \r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 订单编号:                    25\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 下单时间:            02-22 17:46\r\n*line \r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 菜名                  数量  单价\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 口碑券专用菜-1(份)     1    10.0\r\n*line \r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 柳橙汁(大份)           1    0.05\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 规格菜(小)             1     5.0\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 规格菜-口味(小)        1     5.5\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l  做法：去冰5成熟\r\n*line \r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 消费金额:                  20.55\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 打包费用:                    0.0\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 配送费用:                    0.0\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 扫码折扣:                  10.28\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 支付折扣:                   5.21\r\n!hz l\r\n!asc l\r\n*text l 实收金额:                ￥5.06\r\n*feedline 1\r\n!hz l \r\n!asc l\r\n!gray 8 \r\n*text r                         [已支付]\r\n!hz l\r\n!asc l\r\n*text l 姓名:唾沫\r\n*feedline 1\r\n!hz l\r\n!asc l\r\n*text l 电话:15860288200\r\n*feedline 1\r\n!hz l\r\n!asc l\r\n*text l 地址:她咯图咯\r\n*feedline 1\r\n!hz n \r\n!asc n\r\n!gray 5 \r\n*text l 打印时间:       2017-03-02 10:47\r\n*feedline 5 \r\n"

    },
    "extend_params":
    {
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
        <td>固定ums.device.print.cpuhqbfa</td>
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
        <th align="left" colspan="6">打印内容</th>
    </tr>
    <tr>
        <td>-</td>
        <td>message</td>
        <td>●</td>
        <td>长度为8位</td>
        <td>-</td>
        <td>打印规范参见<br>《<a href="../attachment/银商移动刷卡终端打印规范_20140604_V1.2.pdf">银商移动刷卡终端打印规范</a>》</td>
    </tr>
    <tr>
        <th rowspan="2">06</th>
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
    "business_id": "ums.device.print.cpuhqbfa",
    "main_code": "MC_110001",
    "main_msg": "接口调用成功",
    "sub_code": "SC_100300",
    "sub_code_platform": "03",
    "sub_msg": "业务处理成功",
    "data":
    {
        "deviceId": "00011006200000579432"
    },
    "extra":
    {
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
        <td>固定ums.device.print.cpuhqbfa</td>
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
        <td>打印时的刷卡POS设备号</td>
    </tr>
</table>
