import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;

public class SimpleDESExample {
    public static void main(String[] args) {
        String plaintext = "0123456789ABCDEF"; // 16 characters
        String keyString = "12345678"; // 8-byte key

        // Create a DES key from the key string
        byte[] keyBytes = keyString.getBytes("UTF-8");
        DESKeySpec desKeySpec = new DESKeySpec(keyBytes);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
        SecretKey key = keyFactory.generateSecret(desKeySpec);

        // Create a DES cipher instance for encryption
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key);

        // Encrypt the plaintext
        byte[] plaintextBytes = plaintext.getBytes("UTF-8");
        byte[] encryptedBytes = cipher.doFinal(plaintextBytes);

        // Create a DES cipher instance for decryption
        cipher.init(Cipher.DECRYPT_MODE, key);

        // Decrypt the ciphertext
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);

        // Convert the decrypted bytes back to a string
        String decryptedText = new String(decryptedBytes, "UTF-8");

        System.out.println("Plaintext: " + plaintext);
        System.out.println("Encrypted: " + new String(encryptedBytes, "UTF-8"));
        System.out.println("Decrypted: " + decryptedText);
    }
}
