#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int MAXOFIDENTIFIER = 25;

enum TokeType{
    IDENTIFIER = 1,
    INTEGER,
    ADD,
    SUB,
    ASSIGN
};

struct TableNode {
    int type;
    char token[MAXOFIDENTIFIER];
};

TableNode tokenTable[MAX];
int tableNum = 0;

bool errorflag = false;

enum ErrorType {
    UNKNOWNIDENTIFIER
};

void Error(ErrorType errorType, const char* str){
    errorFlag = True;
    cout << "Error " << endl;

    switch(errorType)
    {
    case UNKNOWNIDENTIFIER:
        cout << "Unknown identifier " << str << "! \n";
        break;
}

void Scanner(const char* sourceCode){
    int codeLength = strlen(sourceCode);
    int chIndex = 0;
    int tableIndex = 0;

    while(chIndex < codeLength){
        while(isspace(sourceCode[chIndex]));
            chIndex++;
        if(chIndex >= codeLength)
            break;
        if(isalpha(sourceCode[chIndex]) || sourceCode[chIndex] == '_'){
            char str[MAXOFIDENTIFIER];
            int strlen = 0;

            while(isalnum(sourceCode[chIndex]) || sourceCode[chIndex] == '_'){
                str[strlen++] = sourceCode[chIndex++];
            }

            str[strlen] = '\0';

            tokenTable[tableIndex].type = IDENTIFIER;
            strcpy(tokenTable[tableIndex].token,str);
            tableIndex++;
        }
        else if(isdigit(sourceCode[chIndex])){
            char str[MAXOFIDENTIFIER];
            int strlen = 0;

            while(isdigit(sourceCode[chIndex])){
                str[strLen++] = sourceCode[chIndex++];
            }
            str[strlen] = '\0';
            tokenTable[tableIndex].type = INTEGER;
            strcpy(tokenTable[tableIndex].token, str);
            tableIndex++;
        }
        else{
            char str[2] = {sourceCode[chIndex],'\0'};
            switch (sourceCode[chIndex])
            {
                case "+":
                    tokenTable[tableIndex].type = ADD;
                    break;
                case "-":
                    tokenTable[tableIndex].type = SUB;
                    break;
                case "=":
                    tokenTable[tableIndex].type = ASSIGN;
                    break;
                default:
                    Error(UNKNOWNIDENTIFIER, str);
                    return;
            }
            strcpy(tokenTable[tableIndex].token, str);
            tableIndex++;
            chIndex++;
        }
    }

    tableNum = tableIndex;
}



int main (){
    char sourceCode[MAX];
    cout << "Enter the source code (input '#' to end): \n";

    cin.getline(sourceCode, MAX, '#');
    Scanner(sourceCode);


    cout<<"Token: \n";
    for (int i = 0; i < tableNum; i++)
    {
        switch (tokenTable[i].type)
        {
        case IDENTIFIER:
            cout << "Identifier: "<< tokenTable[i].token << endl;
            break;
        
        case IDENTIFIER:
            cout << "Integer: "<< tokenTable[i].token << endl;
            break;
        case ADD:
            cout << "Operator: + \n";
            break;
        case SUB:
            cout << "Operator: - \n";
            break;
        case ASSIGN:
            cout << "Operator: = \n";
            break;
        default:
            break;
        }
    }
    if(errorflag)
        return 0;
    
    return 0;
}