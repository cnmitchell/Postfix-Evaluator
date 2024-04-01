// Name: Chloe Mitchell
// File Name: prog3.cpp
// Date: 27 Oct. 2023
// Program Description: This program reads in a postfix expression from an entered file and evaluates it by parsing and
// using a linked list implementation of a stack.
#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
using namespace std;

bool isOperator(string); //this functions returns true if the token is one of the allowed operators
bool isOperand(string); //this function returns true if the token is a digit
int evaluate(int, int, string); //this function evaluates the postfix expression

int main(int argc, char* argv[]) {


    if (argc == 1) {
        cout << "No file has been entered" << endl;
        return 0;
    }


    ifstream inFile(argv[1]); //opening file
    if (!inFile) { //checking if its in the files
        cout << "Not in file!" << endl;
        exit(0);
    }

    Stack* myStack = new Stack;
    char expression[80];
    int result;
    while (inFile.getline(expression, 80)) {
        cout << expression;
        char *token = strtok(expression, " ");
        while (token != NULL) {

            if (isOperand(token))
                myStack->push(stoi(token));

            if(isOperator(token)){
                int popVal1 = myStack->pop();
                int popVal2 = myStack->pop();
                if(popVal1 >=0 && popVal2 >=0) {
                    int pushVal = evaluate(popVal1, popVal2, token);
                    myStack->push(pushVal);
                }
                else{
                    cout << " (Error : too many operators)" << endl;
                    token = NULL;
                }
            }

            //checking if operator is valid
            if(token !=NULL) {
                if (!isOperator(token) && !isOperand(token)) {
                    cout << " (Error : invalid operator)" << endl;
                    myStack->clear();
                    token = NULL;
                }
            }
            token = strtok(NULL, " ");
        }
        result = myStack->pop();

        //checking if stack is not empty after popping result
        if(!myStack->isEmpty()){
            cout << " (Error : too many operands)" << endl;
            myStack->clear();
        }
        else {
            if (result >= 0)
                cout << " = " << result << endl;
        }
        }

        inFile.close();
        delete myStack;

        return 0;
    }


bool isOperand(string str){
    if(!isdigit(str[0]))
        return false;
    else
        return true;
}

bool isOperator(string sign){
    if(sign == "+" || sign == "-" || sign == "*" || sign =="/" || sign == "%" || sign == "^")
        return true;
    else
        return false;
}

int evaluate(int popVal1, int popVal2, string sign){
    if(sign == "+")
        return popVal2 + popVal1;
    if(sign == "-")
        return popVal2 - popVal1;
    if(sign == "*")
        return popVal2 * popVal1;
    if(sign == "/")
        return popVal2 / popVal1;
    if(sign == "%")
        return popVal2 % popVal1;
    else{ //(sign == "^")
        if(popVal1 == 0)
            return 1;
        else{
            int temp = popVal2;
            for(int i=1; i < popVal1; i++)
                popVal2 = popVal2 * temp;
            return popVal2;
        }
    }
}