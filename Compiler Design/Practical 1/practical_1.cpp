#include <bits/stdc++.h>
using namespace std;

void checkDFA(string inputString, string currState, set<string> &acceptState, map<string, int> &transitions)
{
    for (int i = 0; i < inputString.length(); i++)
    {
        string temp = currState + inputString[i];
        currState = to_string(transitions[temp]);
    }

    if (acceptState.find(currState) != acceptState.end())
    {
        cout << inputString << " is valid" << endl;
    }
    else
    {
        cout << inputString << " is Invalid" << endl;
    }
}

int main()
{
    vector<string> state = {"0", "1", "2"};
    vector<string> alphabet = {"a", "b", "c"};
    string startState = "0";
    set<string> acceptState = {"2"};
    map<string, int> transitions = {{"0a", 1}, {"0b", 0}, {"0c", 0}, {"1a", 2}, {"1b", 1}, {"1c", 1}, {"2a", 1}, {"2b", 2}, {"2c", 2}};

    vector<string> userInput = {"aaab", "aaaab", "aa", "b"};
    for (int i = 0; i < userInput.size(); i++)
    {
        checkDFA(userInput[i], startState, acceptState, transitions);
    }

    return 0;
}