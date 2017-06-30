<h1 align="center">
  <center><font size="6">全民付收银台插件集成说明</font></center>
	<br/>
	<img width="200" src="https://www.chinaums.com/chinaums/images/logo.png" alt="chinaums">
	<br/>
</h1>


### 产品定位  
全民付收银台插件是为**移动端应用**量身打造的领先支付产品，你只需要通过一个SDK一次接入便可以让你的APP支持以下**主流支付方式**：
- 银行卡：
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_unionpay.png" height="30" />
- 预付卡
- <a href="http://cn.unionpay.com/zt/2016/127198856/">银联云闪付</a>：
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_applepay.png" height="30" />、
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_yunshanfu.png" height="30" />
- 银联钱包：
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_ylqb.png" height="30" />
- 微信：
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_weixin.png" height="30" />
- 支付宝：
  <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/logo_alipay.png" height="30" />  
  
  
### 使用场景
  - 手机/PAD，通过蓝牙与易POS连接，进行银行卡、预付卡、银联云闪付等方式支付
  - 一体化智能终端，通过U架构服务与智能终端交互，进行银行卡、预付卡、银联云闪付等方式支付
  - 手机/PAD，扫码用户二维码进行支付
  

### 商户联调联系方式    
  - **email： qmf_cashier@chinaums.com**  
  - **电话： 021-60133552**  


### 支付插件的形式  
  - iOS SDK      -  商户可集成至自有app。[集成方法请点击进入查看](../master/documents/ios.sdk.doc.md)  
  - android SDK  
    -  apk形式：商户自由app与支付插件独立存在。[集成方法请点击进入查看](../master/documents/android.apk.doc.md)  
    -  aar形式：商户可集成至自由app。[集成方法请点击进入查看](../master/documents/android.aar.doc.md)  
  

### 主要功能
   - 交易发起类
     - [消费接口（支持银行卡，预付卡，银联云闪付，微信、支付宝、银联钱包等钱包类支付）](../master/documents/api/api.01.trade.pay.md)
     - [消费撤销接口](../master/documents/api/api.02.trade.pay.cancel.md)
     - [联机退货接口（支持银行卡，银联云闪付，微信、支付宝、银联钱包等钱包类原交易的退货）](../master/documents/api/api.03.trade.refund.md)
     - [预授权接口](../master/documents/api/api.04.trade.preauth.md)
     - [预授权完成接口](../master/documents/api/api.05.trade.preauth.complete.md)
     - [预授权撤销接口](../master/documents/api/api.06.trade.preauth.cancel.md)
     - [预授权完成撤销接口](../master/documents/api/api.07.trade.preauth.complete.cancel.md)
   - 交易查询类
     - [交易查询接口](../master/documents/api/api.41.trade.query.order.md)
     - [补发签购单接口（支持补打印纸质签购单、补发送短信签购单）](../master/documents/api/api.42.trade.resupply.voucher.md)
     - [余额查询接口（支持银行卡余额查询）](../master/documents/api/api.43.trade.query.balance.md)
     - [打印小票接口（自定义内容进行打印）](../master/documents/api/api.44.device.print.md)
   - 非交易类
     - [刷卡取卡号接口](../master/documents/api/api.81.trade.card.num.get.md)
     - [设备连接接口](../master/documents/api/api.82.device.connect.md)
     - [获取设备号接口](../master/documents/api/api.83.device.get.id.md)
     - [版本信息查询接口](../master/documents/api/api.84.trade.get.version.md)
   - 后台服务接口
     - [后台支付通知接口](../master/documents/comment/comment.notification.push.doc.md)