package des;

import java.io.DataInputStream;

public class HSMUtil {
	
	static public String readString(DataInputStream dis, int length)
			throws Exception {
		byte[] buf = new byte[length];
		dis.read(buf);
		return new String(buf);
	}

	static public String readString(DataInputStream dis) throws Exception {
		int len = dis.readShort();
		byte[] buf = new byte[len];
		dis.read(buf);
		return new String(buf);
	}

	private static final String hexChars = "0123456789ABCDEF";

	/**
	 * byte数组 换 Hex字符串
	 * 
	 * @param data
	 * @return
	 */
	public static String byteArr2HexString(byte[] data) {
		if (data == null)
			return null;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < data.length; i++) {
			byte lo = (byte) (0x0f & data[i]);
			byte hi = (byte) ((0xf0 & data[i]) >>> 4);
			sb.append(hexChars.charAt(hi)).append(hexChars.charAt(lo));
		}
		return sb.toString();
	}

	/**
	 * Hex字符串 转 byte数组
	 * @param hexStr
	 * @return
	 */
	public static byte[] hexString2ByteArr(String hexStr) {
		if (hexStr == null)
			return null;
		if (hexStr.length() % 2 != 0) {
			return null;
		}
		byte[] data = new byte[hexStr.length() / 2];
		for (int i = 0; i < hexStr.length() / 2; i++) {
			char hc = hexStr.charAt(2 * i);
			char lc = hexStr.charAt(2 * i + 1);
			byte hb = hexChar2Byte(hc);
			byte lb = hexChar2Byte(lc);
			if (hb < 0 || lb < 0) {
				return null;
			}
			int n = hb << 4;
			data[i] = (byte) (n + lb);
		}
		return data;
	}

	/**
	 * Hex char 转 byte
	 * @param c
	 * @return
	 */
	public static byte hexChar2Byte(char c) {
		if (c >= '0' && c <= '9')
			return (byte) (c - '0');
		if (c >= 'a' && c <= 'f')
			return (byte) (c - 'a' + 10);
		if (c >= 'A' && c <= 'F')
			return (byte) (c - 'A' + 10);
		return -1;
	}

	public static byte uniteBytes(byte b1, byte b2) {
		return (byte) ((b1 << 4) | (b2 & 0x0F));
	}

	/**
	 * short 转 byte数组
	 * @param i
	 * @return
	 */
	public static byte[] shortToByteArray(short i) {
		byte[] data = new byte[2];
		data[0] = (byte) (i / 256);
		data[1] = (byte) (i % 256);
		return data;
	}

	/**
	 * byte数组 转 short
	 * @param data
	 * @return
	 */
	public static short byteArrayToShort(byte[] data) {
		return (short) (((int) data[0]) * 256 + ((int) data[1]));
	}

}
