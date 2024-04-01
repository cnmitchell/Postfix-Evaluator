// Name: Chloe Mitchell
// File Name: stack.h
// Date: 27 Oct. 2023
// Program Description: This is the header file that creates the linked list structure and declares all of the functions
//that are defined in stack.cpp and used in prog3.cpp/
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
    int count;
public:
    Stack();
    ~Stack();
    void push(int item);
    int pop();
    bool isEmpty();
    void clear();
};