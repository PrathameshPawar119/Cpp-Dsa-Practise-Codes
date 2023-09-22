#include <iostream>

using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;
    
    Stack(int size){
        this->size = size;
        arr = new int [size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }else{
            cout << "Stack Overflow"<< endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }

    int peak(){
        if(top >= 0){
            return arr[top];
        }else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};

class Node{
    public:
    int data;
    Node* next;

    Node(int n){
        this->data = n;
        this->next = NULL;
    }
};

class StackL{
    public:
    Node* top;

    StackL(){
        top = NULL;
    }

    void push(int data){
        Node *temp = new Node(data);
        if(!temp){
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->next = top;
        top = temp;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack Underflow" << endl;
            return;
        }else{
            Node * temp;
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peak(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    
};

int main(){
    // Array vala stack
    Stack st(5);

    st.push(22);
    cout << st.peak() << endl;
    st.push(33);
    cout << st.peak() << endl;
    st.pop();
    cout << st.isEmpty()<<endl;
    st.pop();
    cout << st.isEmpty()<<endl;
    cout << st.peak() << endl<<endl;

    // LL vala stack
    StackL stl;
    stl.push(12);
    cout << stl.peak() << endl;
    stl.pop();
    stl.pop();
    

}