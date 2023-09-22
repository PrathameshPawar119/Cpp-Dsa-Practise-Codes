#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int val = this->data;
        this->next = NULL;
        cout << "Node done free "<< val <<endl;
    }
};

void insertHead(Node* &head, int n)
{
    Node* temp = new Node(n);
    temp -> next = head;
    head = temp;
}
void deleteHead(Node* &head)
{
    Node* temp = head;
    head = head -> next;
    delete temp; 
}

void insertTail(Node* &tail, int n)
{
    Node* temp = new Node(n);
    tail -> next = temp;
    tail = temp;
    // tail will be temp now, next will be null
}
// void deleteTail(Node* &tail)
// {
    
// }

void deleteNode(Node* &head, Node* &tail, int index)
{
    if(index == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp; 
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt <= index)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void insertAfterNode(Node* &head, int n, int d)
{
    Node* temp = head;

    while(temp->data != n)
    {  // here we will stop when found temp  int n
        temp = temp->next;
    }

    Node* newNode = new Node(d);
    auto t2 = temp->next;
    temp->next = newNode;
    newNode->next = t2;

}

void insertAtPosition(Node* &head, Node* &tail, int index, int d)
{
    if(index == 1)
    {
        // index is head
        insertHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < index-1)
    {
        temp = temp -> next; 
        cnt++;
    }

    if(temp -> next == NULL)
    {
        // index is tail, so update tail
        insertTail(tail, d);
        return;
    }

    Node* NodeToInsert = new Node(d);
    auto t2  = temp -> next;
    temp -> next = NodeToInsert;
    NodeToInsert->next = t2;
}

void printLL(Node* &head)
{
    Node* temp = head;  
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseRecursive(Node* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* chotaHead = reverseRecursive(chotaHead->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

Node* reverseLL(Node* &head, Node* &tail){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;

    Node* forward = NULL;

    tail = head;
    while(curr != NULL ){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
 
    return prev;

}

int main()
{
    Node* n1 = new Node(11);
    printLL(n1);

    Node* tail = n1;
    Node* head = n1;

    cout <<endl<< "Insertion Tail"<<endl;
    insertTail(tail, 6);
    insertTail(tail, 32);

    printLL(head);

    cout <<endl<< "Insertion Head"<<endl;
    insertHead(head, 432);
    printLL(head);

    cout <<endl<< "Insertion at Position"<<endl;
    // insertAfterNode(head, 11, 333);
    insertAtPosition(head, tail, 5, 333);
    printLL(head);

    cout <<endl<< "Deletion Head"<<endl;
    deleteHead(head);
    printLL(head);

    cout <<endl<< "Deletion Node" <<endl;
    deleteNode(head, tail, 2);
    printLL(head);



    // head = reverseLL(head, tail);
    head = reverseRecursive(head);
    printLL(head);

    cout <<endl<< "head -> "<< head->data << endl;
    cout << "tail -> "<< tail->data << endl;
    return 0;
}