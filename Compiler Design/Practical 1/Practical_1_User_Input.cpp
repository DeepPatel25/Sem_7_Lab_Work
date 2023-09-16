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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int numberOfState, numberOfAlphabet, numberOfAcceptState, numberOfTransitions;
    string startState;
    vector<string> state, alphabet;
    set<string> acceptState;
    map<string, int> transitions;

    cin >> numberOfState;
    for (int i = 0; i < numberOfState; i++)
    {
        string temp;
        cin >> temp;
        state.push_back(temp);
    }

    cin >> numberOfAlphabet;
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        string temp;
        cin >> temp;
        alphabet.push_back(temp);
    }

    cin >> startState;

    cin >> numberOfAcceptState;
    for (int i = 0; i < numberOfAcceptState; i++)
    {
        string temp;
        cin >> temp;
        acceptState.insert(temp);
    }

    numberOfTransitions = numberOfState * numberOfAlphabet;
    for (int i = 0; i < numberOfTransitions; i++)
    {
        string temp1;
        int temp2;
        cin >> temp1 >> temp2;

        transitions[temp1] = temp2;
    }
    
    return 0;
}