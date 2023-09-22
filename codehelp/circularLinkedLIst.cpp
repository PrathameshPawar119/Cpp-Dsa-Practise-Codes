#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &tail, int elem, int d){
    if(tail == NULL){
        // list is empty
        Node* n1 = new Node(d);
        tail = n1;
        n1 -> next = n1;
    }
    else{
        // list is not empty
        Node*curr = tail;
        while(curr -> data != elem)
        {
            curr = curr->next;
        }

        // assuming curr is present
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int elem)
{
    Node* curr = tail;
    Node* pre = NULL;

    while(curr -> data != elem)
    {
        pre = curr;
        curr = curr->next;
    }

    pre->next = curr->next;
    if(curr == pre){
        // 1node case
        tail = NULL;
    }
    else if(tail == curr ){
        //2node case
        // update tail
        tail = pre;
    }
    curr->next = NULL;
    delete curr;
}

void print(Node* tail)
{
    Node* temp = tail;

    if(tail == NULL)
    {
        cout << " List is empty"<<endl;
        return;
    }

    do{
        cout << tail -> data << " ";
        tail = tail ->next;
    }while(tail != temp);
    cout << endl;
}

int main()
{
    // Node* n1 =  new Node(12);
    Node* tail = NULL;

    insertNode(tail, 1, 11);
    insertNode(tail, 11, 22);
    insertNode(tail, 22, 7);
    insertNode(tail, 7, 17);
    print(tail);

    deleteNode(tail, 22);
    print(tail);
    
}