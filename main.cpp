#include <iostream>
#include <string>

using namespace std;

// Node Creation
class Node {
public:
    string value;
    Node* next = NULL;
    
    Node();
    Node(string val);
      
};

Node::Node() {
    
}

Node::Node(string val) {
    value = val;
}

class Stack {
private:
    Node* top = NULL;
    Node* bottom = NULL;
    int length = 0;
public:
    Stack();
    Node* peak();
    Node* push(string val);
    Node* pop();
    void display();
};

Stack::Stack() {
}

Node* Stack::peak() {
    if (length != 0)
        cout << top->value << endl;
    return top;
}

Node* Stack::push(string val) {
    Node* newNode = NULL;
    newNode = new Node(val);
    if (length == 0) {
        top = newNode;
        bottom = newNode;
    } else {
        Node* holdingPointer = top;
        top = newNode;
        top->next = holdingPointer;
    }
    length++;
    return newNode;
}

Node* Stack::pop() {
    if (length == 0)
        return top;
    
    if (top == bottom)
        bottom = NULL;
    Node* holdingPointer = top;
    top = top->next;
    length--;
    return holdingPointer;
}

void Stack::display() {
    Node* head = top;
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "length: " << length <<endl;
}


int main(){
    Stack* myStack = NULL;
    myStack = new Stack();
    myStack->peak();
    myStack->push("google");
    myStack->push("udemy");
    myStack->push("discord");
    myStack->display();
    Node* danglingPointer = myStack->pop();
    delete danglingPointer;
    myStack->display();
    myStack->peak();
    
    
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    
    // allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();
    
    // Assign value values
    one->value = "1";
    two->value = "2";
    three->value = "3";
    
    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;
    
    // print the link list value
    head = one;
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}