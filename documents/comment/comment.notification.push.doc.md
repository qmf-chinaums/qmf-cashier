## 支付消息实时推送使用说明
当商户通过本插件进行支付，由于各种原因导致商户客户端或者商户系统无法实时获得支付信息数据。  
针对这种情况，开发此接口来实时转发支付成功信息。  
<hr>
  

* 接口说明  
  - 终端商户告知银商分公司实时推送通知**URL地址**，由银商分公司工作人员在“手机运维管理平台--线下插件商户基本信息维护”中添加。  
    见下图：
    <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/notify_url.png" />
  - 本功能会在支付成功时将消息推送到商户指定的回调URL地址，所有参数采用POST方式推送。  
  - 后台会通过3DES对传送的支付信息进行**加密**，并对**加密后的内容**进行RSA签名。3DES密钥会通过邮件方式给各个商户。  
  - 商户需要**自行**实现URL通知功能的服务，并在接收消息时需要对接收到的参数进行验签和解密操作。
  - 验签算法为RSA。<a href="../../documents/attachment/ums_publickey.txt">点击下载RSA签名生产公钥</a>  
  - 加解密算法为3DES
  - 3DES解密及验签公钥见下图
    <img src="https://github.com/qmf-chinaums/qmf-cashier/blob/master/documents/attachment/notify_key.png" />

* 发送与接收方式
  - 手机平台发送
    <table style="text-align:left;">
      <tr>
          <th>参数名</th>
          <th>参数说明</th>
      </tr>
      <tr>
          <td>params</td>
          <td>向商户传送的支付信息的数据，该字段  为<strong>json格式</strong>并经  3DES加密后传给商户。<br>3DES秘钥信息  目前由平台为每个不同商户自动生成，密钥  会以邮件形式通知商户。</td>
      </tr>
      <tr>
          <td>signature</td>
          <td>签名信息，采用加密机对params进行  签名后，得到的签名信息。<br>商户先用  <a   href="../../documents/attachment/  ums_publickey.txt">生产公钥</a>验签  通过后，再params内容解密。</td>
      </tr>
    </table>  
  - params相关字段说明

    ``` json
    {
      "account": "621444******0038",
      "amount": "1",
      "batchNo": "000001",
      "currencyCode": "156",
      "dealDate": "2015-02-03",
      "dealStatus": "1",
      "dealTime": "10:08:51",
      "deviceId": "00011003130000579141",
      "liqDate": "0202",
      "merchantId": "898000156911002", 
      "merchantName": "绫致服装*****", 
      "merchantOrderId": "000000000000001",
      "orderId": "642015020326960682", 
      "posSeqId": "468576",
      "refId": "000105063751",
      "subInst": "101600",
      "termId": "00019130"
    }
    ```

    <table style="text-align:left;">
      <tr>
          <th>参数名</th>
          <th>参数说明</th>
      </tr>
      <tr>
          <td>account</td>
          <td>银行卡号(前六后四，中间部分用*标  识)</td>
      </tr>
      <tr>
          <td>amount</td>
          <td>交易金额(单位:分)</td>
      </tr>
      <tr>
          <td>posSeqId</td>
          <td>POS流水号</td>
      </tr>
      <tr>
          <td>batchNo</td>
          <td>批次号</td>
      </tr>
      <tr>
          <td>currencyCode</td>
          <td>交易币种</td>
      </tr>
      <tr>
          <td>merchantId</td>
          <td>商户代码</td>
      </tr>
      <tr>
          <td>merchantName</td>
          <td>商户名称</td>
      </tr>
      <tr>
          <td>dealDate</td>
          <td>受卡方所在日期(yyyy-MM-dd)</td>
      </tr>
      <tr>
          <td>dealTime</td>
          <td>受卡方所在时间(hh:mm:ss)</td>
      </tr>
      <tr>
          <td>refId</td>
          <td>参考号</td>
      </tr>
      <tr>
          <td>termId</td>
          <td>终端号</td>
      </tr>
      <tr>
          <td>dealStatus</td>
          <td>交易状态(1:支付成功、2:支付失败、  3:支 付中、4:已撤销、5:撤销中、6:已退  货、 7:退货中、8退货失败)</td>
      </tr>
      <tr>
          <td>orderId</td>
          <td>订单号</td>
      </tr>
      <tr>
          <td>merchantOrderId</td>
          <td>商户订单号</td>
      </tr>
      <tr>
          <td>subInst</td>
          <td>分支机构</td>
      </tr>
      <tr>
          <td>liqDate</td>
          <td>清算日期(MMdd)</td>
      </tr>
      <tr>
          <td>deviceId</td>
          <td>设备号</td>
      </tr>
    </table>   
  - 商户返回参数相关字段说明

    ``` json
    {
      "orderId" : "642015012726955805",
      "merchantMsgProcessId" :   "000000000000000",
      "merchantMsgProcessTime" :   "2015-02-02 13:00:00",
      "merchantRecMsgProcessState" : "1"
    }
    ```

    <table style="text-align:left;">
      <tr>
          <th>参数名</th>
          <th>参数说明</th>
          <th>是否必传</th>
      </tr>
      <tr>
          <td>orderId</td>
          <td>传入消息的orderId</td>
          <td>Y</td>
      </tr>
      <tr>
          <td>merchantMsgProcessId</td>
          <td>商户接收消息后的信息处理ID</td>
          <td>Y</td>
      </tr>
      <tr>
          <td>merchantMsgProcessTime</td>
          <td>商户消息处理时间(yyyy-MM-dd   hh:mm:ss)</td>
          <td>Y</td>
      </tr>
      <tr>
          <td>merchantRecMsgProcessS   tate</td>
          <td>商户处理结果状态(0 失败， 1成功)  </td>
          <td>Y</td>
      </tr>
    </table> 

* 测试数据样例     
  - 加密后的数据  testParams  
  ```
  // 银商通知接口中的params内容
    
  8612F080DD8A26133C06DC5DA8DC13F282053CC996855EABC2A536A98F6085CE3EB5FAC4DB4EBAC406ED0BC28D8DA5DDF206C273F5266DE07D9B6FD32D4A99807C84E2B84E38565BE90475C45305D309EF77BDF5092D4DCEDB592941244A335DB33AFC59D00B260CA3AB03A6A7EBBC2F5E288F7B4D4512B9208CD9A5FFF438B9DC1938369FE14D66B7FDE006840114EA23E4D76877D008F891C8CCF09366CB23F9ACF6CAECA232AF7AEAD3FC2DC8E47773E851C6E1B6F1238B82E3BBEB6309484748D04E35B29E265A22281A26824271B18B0AAE1EEBD1561894DDA94D6ECEC80DE088BF86E9965ADC6445F26FC6FD70FEE50A9C9F2FFC9FA3FE18A401C69E453295A5B33FBA5B023B1FD398CF00C7942D29F36ECA7B71CD66C5D5F909799C4EC0F8F3DCFFEC24244C910C599E49FD50CA3369CAF05D0D7C2837319153923130622181DB4118B9614A6A5A9BB5F8B4BCEDE209BBCF93D216E3506185F8687739A25905D961909B4F9A1AAEA210250A845D005E9FC0CF5AE9EB63825D65C15CFD1AF7B507F6D289FD58EF8DA49AE69AF9E98677F5D212889E7915293011C56E1F8948CFD3C1CF918DCDF99383F3F5BFBBC0B21F7CCAAB84FEB415751DCACF8E949C7A21F97D260E8A743385BA78AB5F80088A36792DA2E51EB42A49E55416C7E6293C47FFD0251545A67AEF008E1041DA445E0B29F6F4858FFB54AD685A4133CE93160378CD7846357C92A5A1C0A3C7E1A85FAF1F53C10932963276CDF4E809CDB74ABAFDD936BDA142B58BC9C00F8B430F9C905B0BEAC154760B97331CF13BB1F20095AAB7F0DB24F788E1C2E650B3EEF2DD1C67BED7078E106670D38CC2C727A4A9CB245F7AB6FDB6D585DB5B7AD55F2FBFEAB4923891ED5D36AAB01635484C7A01F3654BC5546A
  
  ```

  - 签名数据  testSignature    
    
  ```
  // 银商通知接口中的signature内容

  6364CA34C517ABBEF0D8BD78A9579CE38CA3329376575A8B5C869F9995692310F3D0266BE0E33FF3FB9FBEA01AFEAAD5BAF779C36B8CFBF7D294A763B2E0EAF1299E88ABA6ED5CF3E502307500C8EF644B7128DB138D99D9E2950B3E8F16883258BB49ECD2DC26999894517453BFA1516110EB6C80FF8940A50C655F503ECC3574B559830A6D5E4345C909A0AD3EDC9C44354EBAB5170ABA2C458A4AD2D6254E2C5A380C5F5DA042C8012300349BE56601F8FD43ED101D319C4612AC101A479C46EAFDB58780C58A96CF0199999D794CFAE060224B9C2415A28E6C933F60DEF0957103BBDA4AE771113424693184E2BC38007BFE34BACD21CF6E9292DD150AEC
  
  ```

  - 公钥  testPublicKey  
    
  ```
  // 银商通知接口中的params内容对应的RSA公钥

  MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvx8WfUE6n3dVCtJbLgEFgJaV70WZXq2ouWmHCwNXLjSr4UZ9IibGHX7KTSj/PozyOhdTv0sncIrar1tSIQAWLq5qpP8TVPjMwu9uV/WNg16tnqY/eYowSFex+MlrqAAj1E8Rb3dnRtNrqCPzZr0bZIsxFAdshp+7OgMVqHQ9fIoR3EkYDCJFwx9Ng8u5k4qbuNLAShtcuZRgoMtPDCB14hvLP+eul9W+JUIKv+BTG2v9uMh42Zp3NPas1vdTKtDDX7GAsiu6fex5KT7zYxXNOrg8NYGzAILyFPO8bDosFcd+l/SD+M8WcTmsOA98YjWrOcepBwKrWoWoe7/zQDTv0QIDAQAB
    
  ```  

  - 解密DES key  testDesKey  
    
  ```
  // 银商通知接口中的params内容对应的DES key

  5ae8fb18c4163b90305163462d5c5680 
    
  ```

  - 验签与解密  
  [**点击查看参考代码**](../../code/DESAlgorithm/java/DesEdeUtil.java)  

  ```java
  // 银联商务通知中的加密字段内容  params
  String encryptedString = testParams;
  
  // 进行验签
  boolean signCheck = doSignCheck(encryptedString, testPublicKey, testSignature);
  System.out.println("验签结果:" + signCheck);
  
  if (signCheck) {            
  	// 只有验签通过，才说明该数据是从银联商务推送过来的，才有必要解密
  	// 否则可以忽略掉
      System.out.println("验签通过，进行解密");
      // 测试解密算法
      String decryptedStr = doDecrypt(encryptedString, testDesKey);
      System.out.println("参数解密后的密文:" + decryptedStr);
  }
  ```
