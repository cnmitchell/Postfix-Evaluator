// Name: Chloe Mitchell
// File Name: stack.cpp
// Date: 27 Oct. 2023
// Program Description: This file defines all of the functions in the header file needed for a linked list implementation of a stack
#include <iostream>
#include "stack.h"
using namespace std;

// constructor
Stack::Stack()
{
    top = NULL;
    count = 0;
}

// destructor
Stack::~Stack()
{
    while (top != NULL)
        pop();
}

//clears the stack after each postfix expression is evaluated if needed
void Stack ::clear() {
    while(pop() != -1)
        pop();
}

//adds a new item to the top of the stack
void Stack::push(int item)
{
// should take care of overflow
    Node* tmp = new Node;
    if (tmp != NULL)
    {
        tmp->data = item;
        tmp->next = top;
        top = tmp;
        tmp = NULL;
        count++;
    }
}

//removes an item from the top of the stack
int Stack::pop()
{

// should take care of underflow
    if (top != NULL)
    {
        Node* tmp = top;
        top = top->next;
        int item = tmp->data;
        delete tmp;
        tmp = NULL;
        count--;
        return item;
    }
    else
        return -1;
}

bool Stack::isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
