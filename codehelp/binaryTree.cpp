#include <iostream>
#include<queue>
#include<stack>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter node data: ";
    cin >> data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout <<endl<< "Insert left node for node "<<data<<endl;
    root->left = buildTree(root->left);

    cout <<endl<< "Insert right node for node "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// simple linear order traversal without sapersator
void levelOrderTraversalLinear(Node* root){
    queue<Node* > q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left); 
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

// for reverse level order traversal use stack
// and push right before left
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // only one node in 1st level

    while(!q.empty()){
        Node* temp = q.front();
        q.pop(); // FIFO

        if(temp == NULL){
            // next level
             cout << endl;
            if(!q.empty()){
                // still has some childs so iterate it one more
                q.push(NULL);
            }
        }else{
            cout << temp->data<< " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }


    }

}


void ReverseLevelOrderTraversal(Node* root){
    stack<Node*> st;
    stack<Node*> reverseSt;
    st.push(root);

    while(!st.empty()){

        stack<Node*> tst;
        while(!st.empty()){
            Node* temp = st.top();
            cout << temp->data <<" ";
            reverseSt.push(temp);

            if(temp->left){
                tst.push(temp->left);
            }
            if(temp->right){
                tst.push(temp->right);
            }
            st.pop();
        }

        while(!tst.empty()){
            Node* tstTop = tst.top();
            st.push(tstTop);
            tst.pop();
        }

        cout << endl;
        reverseSt.push(NULL);
    }

    while(!reverseSt.empty()){
        Node* temp = reverseSt.top();
        if(temp == NULL){
            cout << endl;
        }else{
            cout << temp->data << " ";
        }
        reverseSt.pop();
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout <<endl<< "LevelOrderTraversalLinear(root) => "<<endl;
    levelOrderTraversalLinear(root);


    cout <<endl<< "LevelOrderTraversal(root) => "<<endl;
    levelOrderTraversal(root);



    cout <<endl<< "ReverseLevelOrderTraversal(root) => "<<endl;
    ReverseLevelOrderTraversal(root);
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1






// NULL
// 1