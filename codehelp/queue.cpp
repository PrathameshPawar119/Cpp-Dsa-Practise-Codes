#include<iostream>
using namespace std;

class Queue{

    int* arr;
    int qfront;
    int qrear;


    public:

    int qsize;
    Queue(){
        qsize = 100001; // just  assuming
        arr = new int[qsize];
        qfront = 0;
        qrear = 0;
    }

    void enqueue(int data){
        if(qrear == qsize){
            cout << " Queue is Full ";
            return;
        }else{
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue(){
        if(qrear == qfront){
            cout << " Queue is Empty";
            return -1;
        }else{
            int popped = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qrear == qfront){
                // if last element is popped
                // reset the queue
                qfront = 0;
                qrear = 0;
            }

            return popped;

        }
    }

    bool isEmpty(){
        return qrear == qfront;
    }

    bool isFull(){
        return qrear == qsize;
    }

    int front(){
        if(qfront == qrear){
            cout << " Queue is Empty ";
            return -1;
        }else{
            return arr[qfront];
        }
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

class LQueue{
    Node* qfront;
    Node* qrear;

    public:
    int qsize;
    LQueue(){
        qfront = NULL;
        qrear = NULL;
        qsize = 0;
    }

    void enqueue(int data){
        Node* temp = new Node(data);
        if(!temp){
            cout << "Queue Memory Full "<<endl;
            return;
        }

        if(!qfront){
            qfront = temp;
            qrear = temp;
        }else{
            // updating qrear
            qrear->next = temp; // current qrear ka next temp hoga
            qrear = temp; // ab naya qrear last vala hoga
            qsize++;
        }
        
    }

    int dequeue(){
        if(qfront == NULL){
            cout << "Queue is Empty "<< endl;
            return -1;
        }

        Node* temp = qfront;
        int dt = temp->data;

        qfront = qfront->next;
        delete temp;

        qsize--;
        return dt; 
    }

    bool isEmpty(){
        return qfront == qrear;
    }

    int front(){
        if(!qfront)
        {
            cout << "Queue is Empty "<< endl;
            return -1;
        }

        return qfront->data;
    }


};


int main(){
    // Array vala queue

    Queue* q1 = new Queue();
    cout << "Queue is Empty ? " << q1->isEmpty();
    cout << endl;

    q1->enqueue(10);
    q1->enqueue(20);
    q1->enqueue(13);
    q1->enqueue(19);


    
    cout << "queue size " << q1->qsize << endl;

    cout << "qfront "<< q1->front() << endl;

    q1->dequeue();

    cout << "qfront "<< q1->front() << endl;


cout <<endl<<endl<<endl;
// LL vala queue
    LQueue* ql = new LQueue();
    cout << "Queue is Empty ? " << ql->isEmpty();
    cout << endl;

    ql->enqueue(10);
    ql->enqueue(20);
    ql->enqueue(13);
    ql->enqueue(19);


    
    cout << "queue size " << ql->qsize << endl;

    cout << "qfront "<< ql->front() << endl;

    ql->dequeue();

    cout << "qfront "<< ql->front() << endl;
}