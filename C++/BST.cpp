#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(){};
    node(int a){
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef struct node Node;

class BST{

    public:
        Node* root = NULL;
        BST(){}

        BST(BST* B){
            this->root = B->root;
        }

        BST(int* arr,int size){
            for (int i = 0; i < size; i++){
                this->insert(arr[i]);
            }
        }
    
        void insert(int data){
            Node *temp = new Node;
            temp->data = data;
            Node *prev = NULL;
            Node *curr = root;
            if (root == NULL){
                root = temp;
            }
            else{
                while(curr != NULL){
                    prev = curr;
                    if (data>=curr->data){
                        curr = curr->right;
                    }
                    else if (data<curr->data){
                        curr = curr->left;
                    }
                }
                if (prev->data > data){
                        prev->left = temp;
                }
                else{
                    prev->right = temp;
                }
            }
        
        }
        
        void postOrderPrint(Node* root){  
            if (root == NULL)  
                return;  
            postOrderPrint(root->left);
            postOrderPrint(root->right);
            cout<<root->data<<" ";
        }

        void inOrderPrint(Node* root){  
            if (root == NULL)  
                return;  
            inOrderPrint(root->left);
            cout<<root->data<<" "; 
            inOrderPrint(root->right);  
        }

        void preOrderPrint(Node* root){  
            if (root == NULL)  
                return;  
            cout<<root->data<<" ";
            preOrderPrint(root->left); 
            preOrderPrint(root->right);  
        }

        void remove(int d){

        }


};

int main()
{
    int i;

    cout<<"Enter the Operation you want to do";
}



