#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insertInBST(Node* root, int x){
    
    if(!root){
        root = new Node(x);
        return root;
    }

    if(x > root->data){
        root->right = insertInBST(root->right, x);
    }else{
        root->left = insertInBST(root->left, x);
    }

    return root;
}

int kLargeUtil(Node* root, int &i, int k){

    if(!root)
        return -1;

    int right = kLargeUtil(root->right, i, k);

    if(right != -1)
        return right;

    i++;
    if(i == k)
        return root->data;

    return kLargeUtil(root->left, i, k);
}

int KthLargestElement(Node* root, int k){

    int i = 0;
    return kLargeUtil(root, i, k);
}

void inorder(Node* root){
    
    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(void){

    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    inorder(root);
    cout << endl;

    cout << KthLargestElement(root, 2) << endl;

    return 0;
}