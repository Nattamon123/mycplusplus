
// linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Stack {
private:
    int size;
    int* data;
    int top;
public:
    Stack(int size);
    void push(int x);
    bool stackoverflow();
    void display();
    int pop();
    bool isempty();
    int peek();
    char check(string str);
  
};

Stack::Stack(int size) {
    this->size = size;
    this->data = new int[size] {0};
    this->top = -1;
}


int Stack::pop() {
    int x = -1;
  if (this->isempty()) {
        cout << "empty";
    }
    else {
      x = this->data[this->top];
        this->data[this->top] = 0;
        this->top--;
    }
  return x;
}
int Stack::peek() {
    int x = -1;
    if (this->isempty()) {
        cout << "empty";
    }
    else {
        x = this->data[this->top];
  
    }
    return x;
}
bool Stack::isempty() {
    return this->top == -1;
}
void Stack::push(int x) {
    if (this->stackoverflow()) {
        cout << "Stack" << endl;
    }
    else {
        this->top++;
        this->data[this->top] = x;
    }
}
bool Stack::stackoverflow(){
    return this->top == this->size - 1;
}
void Stack::display() {
    for (int i = 0; i < this->size; i++) {
        cout << this->data[i] << " " << flush;
    }
    cout << endl;
}
char check(string str) {
    Stack s(100);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
     
        }
        else if (str[i] == ')') {
            if (s.isempty()) {
                return '(';
            }
            s.pop();
        }
       
    }
    return (s.isempty()) ? ' ' : ')';
}
int main()
{
    string str = "(cos(A)B()";
    cout << check(str);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
