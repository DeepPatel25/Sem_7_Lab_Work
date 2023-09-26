#include <bits/stdc++.h>
using namespace std;

// Function to encrypt a message using the Vigenère cipher
string encrypt(string plaintext, string keyword)
{
    string ciphertext = "";
    int keyLength = keyword.length();

    for (int i = 0; i < plaintext.length(); i++)
    {
        char plainChar = plaintext[i];
        char keyChar = keyword[i % keyLength];

        if (isalpha(plainChar))
        {
            char shift = isupper(plainChar) ? 'A' : 'a';
            char encryptedChar = ((plainChar - shift + keyChar - 'A') % 26) + shift;
            ciphertext += encryptedChar;
        }
        else
        {
            // Non-alphabetical characters are left unchanged
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

// Function to decrypt a message encrypted with the Vigenère cipher
string decrypt(string ciphertext, string keyword)
{
    string plaintext = "";
    int keyLength = keyword.length();

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[i % keyLength];

        if (isalpha(cipherChar))
        {
            char shift = isupper(cipherChar) ? 'A' : 'a';
            char decryptedChar = ((cipherChar - shift - (keyChar - 'A') + 26) % 26) + shift;
            plaintext += decryptedChar;
        }
        else
        {
            // Non-alphabetical characters are left unchanged
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

int main()
{
    string plaintext = "HELLOMYNAMEISDEEP";
    string keyword = "KEY";

    string ciphertext = encrypt(plaintext, keyword);
    cout << "Plaintext: " << plaintext << endl;
    cout << "Keyword: " << keyword << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, keyword);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
