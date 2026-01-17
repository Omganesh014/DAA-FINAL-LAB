#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* insert(node* root, int x) {
    if(root == NULL) {
        root = new node();
        root->data = x;
        root->left = root->right = NULL;
    } else if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

node* findMin(node* root) {
    while(root->left)
        root = root->left;
    return root;
}

node* del(node* root, int x) {
    if(root == NULL) return root;
    if(x < root->data)
        root->left = del(root->left, x);
    else if(x > root->data)
        root->right = del(root->right, x);
    else {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

void inorder(node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    node* root = NULL;
    int n, x, delx;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter element to delete: ";
    cin >> delx;
    root = del(root, delx);

    cout << "Inorder traversal: ";
    inorder(root);
    return 0;
}
