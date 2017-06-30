## 签名字段（sign）说明
签名计算采用RSA算法。  
将请求参数(ums_request)中data下的所有字段，按照ASCII码升序排列后拼接，计算sign值。
<h1></h1>
  

* 商户自行生成私钥```PRIVATE_KEY```与公钥```PUBLIC_KEY```，然后将公钥```PUBLIC_KEY```告知**银联商务分公司**。    
银商分公司工作人员必须在“手机运维管理平台--线下插件商户基本信息维护”中配置商户提供的PUBLIC_KEY，**未正确配置公钥将无法完成交易**  
RSA公私钥可以使用<a href="http://tools.izhong.me/#/key">公私钥生成工具</a>生成，请复制其中的```PKCS5格式私钥```作为私钥，```X509格式公钥```作为公钥。  
  

* 待签名数据   
  - 请求参数示例   
  ```json
  // 请求参数 (ums_request)
  {
    "business_id": "ums.trade.pay.wo8y2lsu",
    "data": {
        "billsMID": "shouji000000004",
        "billsTID": "sj000004",
        "merOrderId": "1498125477091",
        "merOrderDesc": "buy house",
        "amount": "1",
        "operator": "000001",
        "consumerPhone": "12345678901",
        "payType": "BANKCARD",
        "serialNum": "",
        "orgCode": "",
        "isShowOrderInfo": "true",
        "isShowEVoucherPage": "true",
        "saleSlipFavorite": "defaultType",
        "unsupportedCardType": "",
        "couponType": "1",
        "couponNo": "",
        "memo": "指定格式的备注字段"
    },
    "extend_params": {
        "extension": ""
    },
    "sign": "待计算签名数据"
  }
  ```

  - 摘出加签对象字符串（排除value为空的字段），并按照key的ASCII码升序排列，若首字符相等，则比较后一字符，以此类推。排序完成之后，再把所有内容以“&”符号连接起来，如：
    
  ```
    

  amount=1&billsMID=shouji000000004&billsTID=sj000004&couponType=1&consumerPhone=12345678901&isShowEVoucherPage=true&isShowOrderInfo=true&memo=指定格式的备注字段&merOrderDesc=buy house&merOrderId=1498125477091&operator=000001&payType=BANKCARD&saleSlipFavorite=defaultType
  

  ```
  

* 加签示例
  - 参考[SignExample.java](../../code/signAlgorithm/java/SignExample.java)中```byte[] sign(byte[] data, String privateKey)```方法计算签名 。 
    
  ```
  // 示例PRIVATE_KEY，用作计算签名。  
  
    
  MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBALMrqvVZLbTf/T8Aq5dl6s0u+uvYO48E92dw4/tz5Ouey0/pGxqc6rQbaWo6PK6lEiQ88R+fhFvGeJGDfb36TaJOCHLhKJTuMR7H/RSEK3+nANTCeFroEjV9RzdHpqROhFa1rpjWurpcp/4ugMawHATLZ9ya84+zJROl4ZNdQrS9AgMBAAECgYAGuxc7DFSZPOjomv/XOi7t8lvezErAfrFEo4sNATeSWm7M27b28vomNflp0jJBZVYfImL0iyuPvw78eHIa1vJfnE1AuZaGSv800riPUnH2pKaqIavI60g+yYC3ivWds5iNEqrQlml5V+yhEkQv07BB5zZGEGHIz7E90Kz0tLtswQJBAPVlS9G5FSg/3skrL/oax10A6zPOYTDSjBgiC19MJX8gu/3y9kJegf0SRN52vm+d9x+fKOFPuUJPJkjt++AAaNUCQQC66cCn8vFeo0iHg7HmeWtHk3u4DpE1XCUoeN7+5pejsOV0/ThkUJmNwUrK0DWZsur/KHB8TqhT7HAt30af+ZBJAkEA5jGIhwpMi34mmaT2k3GtVFP5TpapWygWnMjKzDFc9z0YvCa+1RFcdK4/hkPzbjbLS5F8wqaLjWU776u227DmpQJAfsohzcuWv8OzZ3mGK/khNKRuwCPhjHi9G/8iBXcWVguhGwLKRgIGp4n+2iTytxgPIJal9yzEMmmojvVuSwZXQQJBAOo6eZMJ1duz94zhTKoe5+l2S/N2sI21EFGlH2j70yzKwaWU6ckFuZG0ciV2p0H98BKdX1gsJLiN9PQy8XflffA=
  
    
  ```

  - 参考[Base64Utils.java](../../code/signAlgorithm/java/Base64Utils.java)中```byte[] encode(byte[] data)```方法，对签名byte数组进行base64编码防止乱码。  
  
  ```
  // 编码后，得到加签后的签名内容
    
  WEEWBP06fJOiVo61seVSu2qUtjjRNtorWhUHwkKY09KMalkTnrnb1EsmuIJySFoHwNIzYEMxaGC8jHekjzhHEHAOZkxyiWHHpeZnYShVbnufPoIQuT47tEUbia7P6ryjFJP3KfhysJMSIGN/Gc6kcn0ufWdZYKD8YLq4ivzIS6E=
    

  ```
  

* 验签示例
  - 参考[Base64Utils.java](../../code/signAlgorithm/java/Base64Utils.java)中```byte[] decode(String data)```方法，对签名字符串进行base64解码。  
  

  - 参考[SignExample.java](../../code/signAlgorithm/java/SignExample.java)中```boolean signCheck(byte[] data, String publicKey, byte[] sign)```验证签名是否正确。
    
  ```
  // 示例PUBLIC_KEY，用作验证签名。  
  
  
  MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCzK6r1WS203/0/AKuXZerNLvrr2DuPBPdncOP7c+TrnstP6RsanOq0G2lqOjyupRIkPPEfn4RbxniRg329+k2iTghy4SiU7jEex/0UhCt/pwDUwnha6BI1fUc3R6akToRWta6Y1rq6XKf+LoDGsBwEy2fcmvOPsyUTpeGTXUK0vQIDAQAB
  
  
  ```