#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "Cleared node "<< this->data <<endl;
        this-> next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertHead(Node* &head, Node* &tail, int d){
    if(head == NULL)
    {
        Node* n1 = new Node(d);
        head = n1;
        tail = n1;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void insertTail(Node* &head, Node*  &tail,  int d)
{
    if(tail == NULL)
    {
        Node* n1 = new Node(d);
        head = n1;
        tail = n1;
    }
    else{
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
void insertAtPosition(Node* &head, Node* &tail, int index, int data)
{
    if(index == 1){
        // insert at head
        insertHead(head, tail, data);
    }
    else{
        Node* temp = head;

        int cnt = 1;
        while(cnt < index-1)
        {
            temp = temp ->next;
        }
        if(temp->next ==  NULL)
        {
            insertTail(head, tail, data);
        }else{
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void deleteHead(Node* &head)
{
    Node* temp = head;
    temp -> next ->prev = NULL;
    head = temp -> next;
    delete temp;
}
void deleteTail(Node* &tail)
{
    Node* temp = tail;
    temp->prev->next = NULL;
    tail = temp -> prev;
    delete temp;
}
void deleteAtPosition(Node* &head, Node* &tail, int index)
{
    if(index == 1){
        deleteHead(head);
    }
    else{
        Node* curr = head;
        Node* pre = NULL;
        int cnt = 1;
        while(cnt < index){
            pre = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr->next == NULL){
            deleteTail(tail);
        }
        else{
        // to delete curr
            pre->next = curr->next;
            curr->prev = NULL;
            delete  curr;
        }

    }
}


int main()
{
    // Node* n1 = new Node(12);
    // print(n1);

    Node* head = NULL;
    Node* tail = NULL;

    cout<<endl<< "InsertHead "<<endl;
    insertHead(head, tail, 14);
    insertHead(head, tail, 11);
    insertHead(head, tail, 19);
    print(head);

    cout <<endl<< "InsertTail" <<endl;
    insertTail(head, tail, 9);
    insertTail(head, tail, 22);
    print(head);


    cout  <<endl<<"Insert at position"<<endl;
    insertAtPosition(head, tail,  2, 44);
    print(head);

    cout <<endl<< "Delete Head"<<endl;
    deleteHead(head);
    print(head);

    cout <<endl<< "Delete Tail"<<endl;
    deleteTail(tail);
    print(head);

    cout <<endl<< "Deleting at position "<<endl;
    deleteAtPosition(head, tail, 2);
    print(head);

    cout <<endl<< "head " << head->data <<", tail "<< tail->data;


}