package des;

import java.nio.ByteBuffer;
import java.security.Key;
import java.security.KeyFactory;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.X509EncodedKeySpec;

import javax.crypto.Cipher;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESedeKeySpec;

import sign.Base64Utils;

public class DesEdeUtil {
    
    /**
     * 加密后的数据（测试用的！！）---> 真实数据:在银商后台通知参数params中
     */
    private static String testParams = "8612F080DD8A26133C06DC5DA8DC13F282053CC996855EABC2A536A98F6085CE3EB5FAC4DB4EBAC406ED0BC28D8DA5DDF206C273F5266DE07D9B6FD32D4A99807C84E2B84E38565BE90475C45305D309EF77BDF5092D4DCEDB592941244A335DB33AFC59D00B260CA3AB03A6A7EBBC2F5E288F7B4D4512B9208CD9A5FFF438B9DC1938369FE14D66B7FDE006840114EA23E4D76877D008F891C8CCF09366CB23F9ACF6CAECA232AF7AEAD3FC2DC8E47773E851C6E1B6F1238B82E3BBEB6309484748D04E35B29E265A22281A26824271B18B0AAE1EEBD1561894DDA94D6ECEC80DE088BF86E9965ADC6445F26FC6FD70FEE50A9C9F2FFC9FA3FE18A401C69E453295A5B33FBA5B023B1FD398CF00C7942D29F36ECA7B71CD66C5D5F909799C4EC0F8F3DCFFEC24244C910C599E49FD50CA3369CAF05D0D7C2837319153923130622181DB4118B9614A6A5A9BB5F8B4BCEDE209BBCF93D216E3506185F8687739A25905D961909B4F9A1AAEA210250A845D005E9FC0CF5AE9EB63825D65C15CFD1AF7B507F6D289FD58EF8DA49AE69AF9E98677F5D212889E7915293011C56E1F8948CFD3C1CF918DCDF99383F3F5BFBBC0B21F7CCAAB84FEB415751DCACF8E949C7A21F97D260E8A743385BA78AB5F80088A36792DA2E51EB42A49E55416C7E6293C47FFD0251545A67AEF008E1041DA445E0B29F6F4858FFB54AD685A4133CE93160378CD7846357C92A5A1C0A3C7E1A85FAF1F53C10932963276CDF4E809CDB74ABAFDD936BDA142B58BC9C00F8B430F9C905B0BEAC154760B97331CF13BB1F20095AAB7F0DB24F788E1C2E650B3EEF2DD1C67BED7078E106670D38CC2C727A4A9CB245F7AB6FDB6D585DB5B7AD55F2FBFEAB4923891ED5D36AAB01635484C7A01F3654BC5546A";
    
    /**
     * des key（测试用的！！）            ---> 真实数据:银商以邮件形式通知
     */
    private static String testDesKey = "f6cbb47b934cb5eb85f1594647e5d017";
    
    /**
     * 公钥（测试用的公钥！！）            ---> 真实数据:银商以其他形式通知
     */
    public static String testPublicKey = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvx8WfUE6n3dVCtJbLgEFgJaV70WZXq2ouWmHCwNXLjSr4UZ9IibGHX7KTSj/PozyOhdTv0sncIrar1tSIQAWLq5qpP8TVPjMwu9uV/WNg16tnqY/eYowSFex+MlrqAAj1E8Rb3dnRtNrqCPzZr0bZIsxFAdshp+7OgMVqHQ9fIoR3EkYDCJFwx9Ng8u5k4qbuNLAShtcuZRgoMtPDCB14hvLP+eul9W+JUIKv+BTG2v9uMh42Zp3NPas1vdTKtDDX7GAsiu6fex5KT7zYxXNOrg8NYGzAILyFPO8bDosFcd+l/SD+M8WcTmsOA98YjWrOcepBwKrWoWoe7/zQDTv0QIDAQAB";
      
    /**
     * 签名数据（测试用的！！）            ---> 真实数据:在银商后台通知参数中
     */
    private static String testSignature = "6364CA34C517ABBEF0D8BD78A9579CE38CA3329376575A8B5C869F9995692310F3D0266BE0E33FF3FB9FBEA01AFEAAD5BAF779C36B8CFBF7D294A763B2E0EAF1299E88ABA6ED5CF3E502307500C8EF644B7128DB138D99D9E2950B3E8F16883258BB49ECD2DC26999894517453BFA1516110EB6C80FF8940A50C655F503ECC3574B559830A6D5E4345C909A0AD3EDC9C44354EBAB5170ABA2C458A4AD2D6254E2C5A380C5F5DA042C8012300349BE56601F8FD43ED101D319C4612AC101A479C46EAFDB58780C58A96CF0199999D794CFAE060224B9C2415A28E6C933F60DEF0957103BBDA4AE771113424693184E2BC38007BFE34BACD21CF6E9292DD150AEC";
        
    public static void main(String[] args) throws Exception {
        
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
        
    }
    
    /**
     * 加密
     * 
     * @param paramString 带加密的参数
     * @param desKey
     * 
     * @return 加密后的内容
     */
    public static String doEncrypt(String paramString, String desKey) {
        String encryptedStr = null;
        try {
            encryptedStr = HSMUtil.byteArr2HexString(DesEdeUtil.desEdeEcbPkcs5Encrypt(paramString.getBytes("utf-8"),
                                                    HSMUtil.hexString2ByteArr(desKey)));
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        return encryptedStr;

    }
    
    /**
     * 解密
     * 
     * @param encryptedString 已加密的字符串
     * @param desKey
     * 
     * @return 加密后的内容
     */
    public static String doDecrypt(String encryptedString, String desKey) {
        
        String decryptedStr = null;
        try {
            decryptedStr = new String((DesEdeUtil.desEdeEcbPkcs5Decrypt(HSMUtil.hexString2ByteArr(encryptedString), 
                                    HSMUtil.hexString2ByteArr(desKey))), "utf-8");
        } catch (Exception e) {
            e.printStackTrace();
        }
                
        return decryptedStr;
        
    }    
    
    /**
     * 验签
     * 
     * @param data 待验签的字符串
     * @param publicKey 公钥
     * @param sign 待验签的字符串的签名数据
     * 
     * @return true: 验签通过    false: 验签失败
     * @throws Exception
     */
    public static boolean doSignCheck(String data, String publicKey, String sign)
            throws Exception {
        byte[] keyBytes = Base64Utils.decode(publicKey);
        X509EncodedKeySpec keySpec = new X509EncodedKeySpec(keyBytes);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        PublicKey publicK = keyFactory.generatePublic(keySpec);
        Signature signature = Signature.getInstance("SHA1withRSA");
        signature.initVerify(publicK);
        signature.update(data.getBytes());
        
        return signature.verify(HSMUtil.hexString2ByteArr(sign));        
    }
    
    private static final Key makeDesKey(byte[] keyData) throws Exception {
        DESedeKeySpec keySpec = new DESedeKeySpec(keyData);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DESede");
        return keyFactory.generateSecret(keySpec);
    }

    /**
     * 3des ede加密，补0
     * 
     * @param data
     * @param keyData
     * @return
     * @throws Exception
     */
    public static byte[] desEdeEcbEncrypt(byte[] data, byte[] keyData)
            throws Exception {
        if (keyData.length < 24)
            keyData = make3DesKey(keyData);
        Key key = makeDesKey(keyData);
        Cipher cipher = Cipher.getInstance("DESede/CBC/NoPadding");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        return cipher.doFinal(addPadding(data));
    }

    public static byte[] desEdeEcbPkcs5Encrypt(byte[] data, byte[] keyData)
            throws Exception {
        if (keyData.length < 24)
            keyData = make3DesKey(keyData);
        Key localKey = makeDesKey(keyData);
        Cipher localCipher = Cipher.getInstance("DESede/ECB/PKCS5Padding");
        localCipher.init(Cipher.ENCRYPT_MODE, localKey);
        return localCipher.doFinal(data);
    }

    /**
     * 3des ede解密
     * 
     * @param data
     * @param keyData
     * @return
     * @throws Exception
     */
    public static byte[] desEdeEcbDecrypt(byte[] data, byte[] keyData)
            throws Exception {
        if (keyData.length < 24)
            keyData = make3DesKey(keyData);
        Key localKey = makeDesKey(keyData);
        Cipher localCipher = Cipher.getInstance("DESede/ECB/NoPadding");
        localCipher.init(Cipher.DECRYPT_MODE, localKey);
        return localCipher.doFinal(addPadding(data));
    }

    public static byte[] desEdeEcbPkcs5Decrypt(byte[] data, byte[] keyData)
            throws Exception {
        if (keyData.length < 24)
            keyData = make3DesKey(keyData);
        Key localKey = makeDesKey(keyData);
        Cipher localCipher = Cipher.getInstance("DESede/ECB/PKCS5Padding");
        localCipher.init(Cipher.DECRYPT_MODE, localKey);
        return localCipher.doFinal(data);
    }

    private static byte[] make3DesKey(byte[] keyData) {
        byte[] key3 = null;
        byte[] key1 = new byte[8];
        ByteBuffer buf = ByteBuffer.wrap(keyData);
        buf.get(key1);
        buf.clear();
        buf = ByteBuffer.allocate(24);
        buf.put(keyData);
        buf.put(key1);
        buf.flip();
        key3 = buf.array();
        buf.clear();
        return key3;
    }

    private static byte[] addPadding(byte[] data) {
        byte[] data2 = data;
        if (data.length % 8 != 0) {
            data2 = new byte[(data.length / 8 + 1) * 8];
            System.arraycopy(data, 0, data2, 0, data.length);
        }
        return data2;
    }

}