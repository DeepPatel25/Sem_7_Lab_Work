#include <bits/stdc++.h>
using namespace std;

// Function to encrypt a message using a 3x3 matrix key
string encrypt(string plaintext, vector<vector<int>> key)
{
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i += 3)
    {
        vector<int> plaintextBlock;
        for (int j = 0; j < 3; j++)
        {
            if (i + j < plaintext.length())
                plaintextBlock.push_back(plaintext[i + j] - 'A');
            else
                plaintextBlock.push_back(0);
        }

        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += key[j][k] * plaintextBlock[k];
            }
            ciphertext += (char)((sum % 26) + 'A');
        }
    }

    return ciphertext;
}

// Function to calculate the modulo of a negative number
int mod(int a, int b)
{
    return (a % b + b) % b;
}

// Function to calculate the inverse of a number modulo 26
int modInverse(int a)
{
    for (int x = 1; x < 26; x++)
    {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1; // No modular inverse exists
}

// Function to decrypt a message using a 3x3 matrix key
string decrypt(string ciphertext, vector<vector<int>> key)
{
    string plaintext = "";
    int det = 0;

    // Calculate the determinant of the key matrix
    for (int i = 0; i < 3; i++)
    {
        det += (key[0][i] * (key[1][(i + 1) % 3] * key[2][(i + 2) % 3] - key[1][(i + 2) % 3] * key[2][(i + 1) % 3]));
    }

    det = mod(det, 26);

    int detInverse = modInverse(det);
    if (detInverse == -1)
    {
        cerr << "Inverse of the determinant does not exist. Unable to decrypt." << endl;
        return "";
    }

    // Calculate the adjugate matrix
    vector<vector<int>> adjugate(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            adjugate[i][j] = mod(((key[(j + 1) % 3][(i + 1) % 3] * key[(j + 2) % 3][(i + 2) % 3]) -
                                  (key[(j + 1) % 3][(i + 2) % 3] * key[(j + 2) % 3][(i + 1) % 3])),
                                 26);
        }
    }

    // Calculate the inverse key matrix
    vector<vector<int>> inverseKey(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverseKey[i][j] = mod((detInverse * adjugate[i][j]), 26);
        }
    }

    // Decrypt the ciphertext
    for (int i = 0; i < ciphertext.length(); i += 3)
    {
        vector<int> ciphertextBlock;
        for (int j = 0; j < 3; j++)
        {
            if (i + j < ciphertext.length())
                ciphertextBlock.push_back(ciphertext[i + j] - 'A');
            else
                ciphertextBlock.push_back(0);
        }

        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += inverseKey[j][k] * ciphertextBlock[k];
            }
            plaintext += (char)((mod(sum, 26)) + 'A');
        }
    }

    return plaintext;
}

int main()
{
    vector<vector<int>> key = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix

    string plaintext = "HELLOMYNAMEISDEEP";
    string ciphertext = encrypt(plaintext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
