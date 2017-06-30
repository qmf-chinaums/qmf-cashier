package sign;

import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

/**
 * 功能说明：签名工具类
 */
public class SignExample {
	
    public static final String SIGNATURE_ALGORITHM = "SHA1withRSA";
    
    /** 加签字段   */
    public static final String content = "amount=1&billsMID=shouji000000004&billsTID=sj000004&couponType=1&consumerPhone=12345678901&isShowEVoucherPage=true&isShowOrderInfo=true&memo=指定格式的备注字段&merOrderDesc=buy house&merOrderId=1498125477091&operator=000001&payType=BANKCARD&saleSlipFavorite=defaultType";
    
    /** 私钥   */
    public static final String PRIVATE_KEY = "MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBALMrqvVZLbTf/T8Aq5dl6s0u+uvYO48E92dw4/tz5Ouey0/pGxqc6rQbaWo6PK6lEiQ88R+fhFvGeJGDfb36TaJOCHLhKJTuMR7H/RSEK3+nANTCeFroEjV9RzdHpqROhFa1rpjWurpcp/4ugMawHATLZ9ya84+zJROl4ZNdQrS9AgMBAAECgYAGuxc7DFSZPOjomv/XOi7t8lvezErAfrFEo4sNATeSWm7M27b28vomNflp0jJBZVYfImL0iyuPvw78eHIa1vJfnE1AuZaGSv800riPUnH2pKaqIavI60g+yYC3ivWds5iNEqrQlml5V+yhEkQv07BB5zZGEGHIz7E90Kz0tLtswQJBAPVlS9G5FSg/3skrL/oax10A6zPOYTDSjBgiC19MJX8gu/3y9kJegf0SRN52vm+d9x+fKOFPuUJPJkjt++AAaNUCQQC66cCn8vFeo0iHg7HmeWtHk3u4DpE1XCUoeN7+5pejsOV0/ThkUJmNwUrK0DWZsur/KHB8TqhT7HAt30af+ZBJAkEA5jGIhwpMi34mmaT2k3GtVFP5TpapWygWnMjKzDFc9z0YvCa+1RFcdK4/hkPzbjbLS5F8wqaLjWU776u227DmpQJAfsohzcuWv8OzZ3mGK/khNKRuwCPhjHi9G/8iBXcWVguhGwLKRgIGp4n+2iTytxgPIJal9yzEMmmojvVuSwZXQQJBAOo6eZMJ1duz94zhTKoe5+l2S/N2sI21EFGlH2j70yzKwaWU6ckFuZG0ciV2p0H98BKdX1gsJLiN9PQy8XflffA=";
    
    /** 公钥   */
    public static final String PUBLIC_KEY = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCzK6r1WS203/0/AKuXZerNLvrr2DuPBPdncOP7c+TrnstP6RsanOq0G2lqOjyupRIkPPEfn4RbxniRg329+k2iTghy4SiU7jEex/0UhCt/pwDUwnha6BI1fUc3R6akToRWta6Y1rq6XKf+LoDGsBwEy2fcmvOPsyUTpeGTXUK0vQIDAQAB";
  
    /**
     * 加签
     * @param data 待签名字符串byte数组
     * @param privateKey 私钥
     * @return 签名
     * @throws Exception
     */
    private static byte[] sign(byte[] data, String privateKey) throws Exception {
        byte[] keyBytes = Base64Utils.decode(privateKey);
        PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(keyBytes);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        PrivateKey privateK = keyFactory.generatePrivate(pkcs8KeySpec);
        Signature signature = Signature.getInstance(SIGNATURE_ALGORITHM);
        signature.initSign(privateK);
        signature.update(data);
        
        return signature.sign();
    }

    /**
     * 验签
     * @param data 待验签字符串
     * @param publicKey 公钥
     * @param sign 签名
     * 
     * @return true:验签通过，说明待验签字符串未被篡改  false:验签失败
     * @throws Exception
     */
    public static boolean signCheck(byte[] data, String publicKey, byte[] sign)
            throws Exception {
        byte[] keyBytes = Base64Utils.decode(publicKey);
        X509EncodedKeySpec keySpec = new X509EncodedKeySpec(keyBytes);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        PublicKey publicK = keyFactory.generatePublic(keySpec);
        Signature signature = Signature.getInstance(SIGNATURE_ALGORITHM);
        signature.initVerify(publicK);
        signature.update(data);
        
        // 验签
        boolean isOk = signature.verify(sign);
        
        return isOk;
    }

    public static void main(String[] args) throws Exception {
    	// 测试加签
    	String sign = doSign(content, PRIVATE_KEY);
        System.out.println("加签内容:" + content);
        System.out.println("签名:" + sign);
        
    	// 测试验签
        boolean isOk = doSignCheck(content, PUBLIC_KEY, sign);
        System.out.println("是否验签通过:" + isOk);
        
    }


    /**
     * 加签
     * @param data
     * @param privateKey
     * @return
     * @throws Exception
     */
    public static String doSign(String data, String privateKey) throws Exception {    
    	// 对待签名数据使用私钥进行加签，得到签名byte数组
    	byte[] signBytes = sign(data.getBytes(), privateKey);
    	
    	// 对签名进行base64编码
    	String signString = new String(Base64Utils.encode(signBytes));

        return signString;
    }

    /**
     * 验签
     * 
     * @param data
     * @param publicKey
     * @param sign
     * @return
     * @throws Exception
     */
    public static boolean doSignCheck(String data, String publicKey, String sign) throws Exception {
    	
    	// 对签名进行base64解码
        byte[] signBytes = Base64Utils.decode(sign);
        
        // 对签名使用公钥进行验证
        boolean isOk = signCheck(data.getBytes(), publicKey, signBytes);
        
    	return isOk;
    }



}
