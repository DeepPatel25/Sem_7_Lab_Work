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

int main()
{
    vector<vector<int>> key = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix

    string plaintext = "HELLOMYNAMEISDEEP";
    string ciphertext = encrypt(plaintext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
