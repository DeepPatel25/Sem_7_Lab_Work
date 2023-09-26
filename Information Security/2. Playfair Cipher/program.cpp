#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> generatePlayFairMatrix(string &key)
{
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string uniqueKey = "";

    for (char c : key)
    {
        if (find(uniqueKey.begin(), uniqueKey.end(), c) == uniqueKey.end())
        {
            uniqueKey += c;
        }
    }

    vector<vector<char>> matrix(5, vector<char>(5));
    int keyIndex = 0, alphaIndex = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyIndex < uniqueKey.length())
            {
                matrix[i][j] = uniqueKey[keyIndex++];
            }
            else
            {
                while (uniqueKey.find(alphabet[alphaIndex]) != string::npos)
                {
                    alphaIndex++;
                }
                matrix[i][j] = alphabet[alphaIndex++];
            }
        }
    }

    return matrix;
}

string playfairEncrypt(string &message, vector<vector<char>> &matrix)
{
    string encryptedMessage = "";
    string processedMessage = message;

    processedMessage.erase(remove_if(processedMessage.begin(), processedMessage.end(), ::isspace), processedMessage.end());
    transform(processedMessage.begin(), processedMessage.end(), processedMessage.begin(), ::toupper);

    for (int i = 0; i < processedMessage.length(); i += 2)
    {
        char first = processedMessage[i];
        char second = (i + 1 < processedMessage.length()) ? processedMessage[i + 1] : 'X';

        int row1, col1, row2, col2;

        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                if (matrix[row][col] == first)
                {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == second)
                {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        if (row1 == row2)
        {
            encryptedMessage += matrix[row1][(col1 + 1) % 5];
            encryptedMessage += matrix[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2)
        {
            encryptedMessage += matrix[(row1 + 1) % 5][col1];
            encryptedMessage += matrix[(row2 + 1) % 5][col2];
        }
        else
        {
            encryptedMessage += matrix[row1][col2];
            encryptedMessage += matrix[row2][col1];
        }
    }

    return encryptedMessage;
}

// Function to find the position of a character in the Playfair matrix
pair<int, int> findPosition(const char c, const vector<vector<char>> &matrix)
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (matrix[row][col] == c)
            {
                return make_pair(row, col);
            }
        }
    }

    // Return an invalid position if the character is not found
    return make_pair(-1, -1);
}

// Function to decrypt a message using the Playfair cipher
string playfairDecrypt(const string &message, const vector<vector<char>> &matrix)
{
    string decryptedMessage = "";
    string processedMessage = message;

    for (int i = 0; i < processedMessage.length(); i += 2)
    {
        char first = processedMessage[i];
        char second = (i + 1 < processedMessage.length()) ? processedMessage[i + 1] : 'X';

        int row1, col1, row2, col2;

        // Find the positions of the characters in the matrix
        pair<int, int> pos1 = findPosition(first, matrix);
        pair<int, int> pos2 = findPosition(second, matrix);

        if (pos1.first == -1 || pos2.first == -1)
        {
            cout << "Invalid characters in the encrypted message." << endl;
            return "";
        }

        row1 = pos1.first;
        col1 = pos1.second;
        row2 = pos2.first;
        col2 = pos2.second;

        // Decrypt the characters
        if (row1 == row2)
        {
            decryptedMessage += matrix[row1][(col1 + 4) % 5];
            decryptedMessage += matrix[row2][(col2 + 4) % 5];
        }
        else if (col1 == col2)
        {
            decryptedMessage += matrix[(row1 + 4) % 5][col1];
            decryptedMessage += matrix[(row2 + 4) % 5][col2];
        }
        else
        {
            decryptedMessage += matrix[row1][col2];
            decryptedMessage += matrix[row2][col1];
        }
    }

    return decryptedMessage;
}

int main()
{
    string key, message;

    cout << "Enter the key :- ";
    cin >> key;

    cout << "Enter the message to encrypt :- ";
    cin.ignore();
    getline(cin, message);

    vector<vector<char>> matrix = generatePlayFairMatrix(key);

    string encryptMessage = playfairEncrypt(message, matrix);
    cout << "Encrypted message :- " << encryptMessage << endl;

    string decryptMessage = playfairDecrypt(encryptMessage, matrix);
    cout << "Decrypted message :- " << decryptMessage << endl;

    return 0;
}