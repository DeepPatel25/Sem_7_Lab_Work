#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the grammar
char *grammar[] = {
    "S->id=E",
    "E->TE'",
    "E'->+TE'",
    "E'->ε",
    "T->(E)T'",
    "T->idT'",
    "T'->*(E)T'",
    "T'->ε"};

// Define the first and follow sets
char *firstSets[] = {
    "id (",
    "id (",
    "+ ε",
    "* ε"};

char *followSets[] = {
    "$ = )",
    "$ + )",
    "+ ε",
    "$ + ) * ε"};

// Predictive Parsing Table
char *parsingTable[4][5];

// Initialize the Predictive Parsing Table
void initializeParsingTable()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            parsingTable[i][j] = NULL;
        }
    }

    // Fill in the predictive parsing table
    parsingTable[0][0] = "S->id=E";
    parsingTable[1][0] = "E->TE'";
    parsingTable[1][1] = "E->TE'";
    parsingTable[1][2] = "E'->+TE'";
    parsingTable[1][3] = "E'->ε";
    parsingTable[2][0] = "T->(E)T'";
    parsingTable[2][1] = "T->idT'";
    parsingTable[3][1] = "T'->*(E)T'";
    parsingTable[3][2] = "T'->ε";
}

// Predictive Parser
void predictiveParser(char *input)
{
    char stack[100];
    int top = -1;
    stack[++top] = 'S';
    int inputIndex = 0;

    printf("Parsing Steps:\n");

    while (top >= 0)
    {
        char stackTop = stack[top];
        char currentInput = input[inputIndex];

        if (stackTop == currentInput)
        {
            printf("Matched: %c\n", currentInput);
            top--;
            inputIndex++;
        }
        else if (stackTop >= 'A' && stackTop <= 'Z')
        {
            int row = stackTop - 'A';
            int col = 0;

            if (currentInput == 'i')
            {
                col = 0;
            }
            else if (currentInput == '(')
            {
                col = 1;
            }
            else if (currentInput == '=')
            {
                col = 2;
            }
            else if (currentInput == '+')
            {
                col = 3;
            }
            else if (currentInput == ')')
            {
                col = 4;
            }

            char *production = parsingTable[row][col];
            if (production == NULL)
            {
                printf("Error! Invalid input.\n");
                break;
            }

            printf("%s\n", production);

            // Pop non-terminal and push production onto the stack
            top--;
            for (int i = strlen(production) - 1; i >= 3; i--)
            {
                if (production[i] != 'ε')
                {
                    stack[++top] = production[i];
                }
            }
        }
        else
        {
            printf("Error! Invalid input.\n");
            break;
        }
    }

    if (top == -1 && input[inputIndex] == '$')
    {
        printf("Parsing successful.\n");
    }
    else
    {
        printf("Parsing failed.\n");
    }
}

int main()
{
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);
    strcat(input, "$"); // Add end marker

    initializeParsingTable();
    predictiveParser(input);

    return 0;
}
