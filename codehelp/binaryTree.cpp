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

// for reverse level order traversal use stack
// and push right before left
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop(); // FIFO

        if(temp == NULL){
            // next change
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


int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout <<endl<< "LevelOrderTraversal(root) => "<<endl;
    levelOrderTraversal(root);
}