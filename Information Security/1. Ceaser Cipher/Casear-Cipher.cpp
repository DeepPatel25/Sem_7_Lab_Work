#include <bits/stdc++.h>
using namespace std;

string EncryptedString(string inputString, int key)
{
    string str = "";

    for (int i = 0; i < inputString.size(); i++)
    {
        char inputChar = inputString[i];
        if (isalpha(inputChar))
        {
            char base = islower(inputChar) ? 'a' : 'A';
            inputChar = ((inputChar - base + key) % 26) + base;
        }
        str += inputChar;
    }
    return str;
}

string DecryptedString(string inputString, int key)
{
    return EncryptedString(inputString, 26 - key);
}

int main()
{
    string inputString = "Deep Patel";
    int key = 5;

    string encryptedString = EncryptedString(inputString, key);
    cout << encryptedString << endl;

    string decryptedString = DecryptedString(encryptedString, key);
    cout << decryptedString;

    return 0;
}