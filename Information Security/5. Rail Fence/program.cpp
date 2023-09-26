#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encrypt a message using the Rail Fence cipher
string railFenceEncrypt(string plaintext, int rails)
{
    vector<string> fence(rails, ""); // Create rails as empty strings

    int rail = 0;
    bool directionDown = true;

    for (char c : plaintext)
    {
        fence[rail] += c;

        if (directionDown)
        {
            rail++;
            if (rail == rails - 1)
            {
                directionDown = false;
            }
        }
        else
        {
            rail--;
            if (rail == 0)
            {
                directionDown = true;
            }
        }
    }

    string ciphertext = "";
    for (string railStr : fence)
    {
        ciphertext += railStr;
    }

    return ciphertext;
}

// Function to decrypt a message encrypted with the Rail Fence cipher
string railFenceDecrypt(string ciphertext, int rails)
{
    vector<string> fence(rails, "");
    vector<int> railLengths(rails, 0);

    int rail = 0;
    bool directionDown = true;

    for (int i = 0; i < ciphertext.length(); i++)
    {
        railLengths[rail]++;

        if (directionDown)
        {
            rail++;
            if (rail == rails - 1)
            {
                directionDown = false;
            }
        }
        else
        {
            rail--;
            if (rail == 0)
            {
                directionDown = true;
            }
        }
    }

    int index = 0;
    for (int railIndex = 0; railIndex < rails; railIndex++)
    {
        for (int j = 0; j < railLengths[railIndex]; j++)
        {
            fence[railIndex] += ciphertext[index++];
        }
    }

    string plaintext = "";
    rail = 0;
    directionDown = true;

    for (int i = 0; i < ciphertext.length(); i++)
    {
        plaintext += fence[rail][0];
        fence[rail] = fence[rail].substr(1);

        if (directionDown)
        {
            rail++;
            if (rail == rails - 1)
            {
                directionDown = false;
            }
        }
        else
        {
            rail--;
            if (rail == 0)
            {
                directionDown = true;
            }
        }
    }

    return plaintext;
}

int main()
{
    string plaintext = "HELLOMYNAMEISDEEP";
    int rails = 3;

    string ciphertext = railFenceEncrypt(plaintext, rails);
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = railFenceDecrypt(ciphertext, rails);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
