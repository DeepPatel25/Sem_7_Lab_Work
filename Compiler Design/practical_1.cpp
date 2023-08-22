#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> state = {"0", "1", "2"};
    vector<string> alphabet = {"a", "b", "c"};
    string startState = "0";
    set<string> acceptState = {"2"};
    map<string, int> mp = {{"0a", 1}, {"0b", 0}, {"0c", 0}, {"1a", 2}, {"1b", 1}, {"1c", 1}, {"2a", 1}, {"2b", 2}, {"2c", 2}};

    string inputString = "aaab";

    for (int i = 0; i < inputString.length(); i++)
    {
        string temp = startState + inputString[i];
        startState = to_string(mp[temp]);
    }

    if (acceptState.find(startState) != acceptState.end())
    {
        cout << inputString << " is valid";
    }
    else
    {
        cout << inputString << " is Invalid";
    }

    return 0;
}