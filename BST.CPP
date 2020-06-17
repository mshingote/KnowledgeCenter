#include <iostream>
using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
}NODE;


NODE* insert(NODE* root, int key) {
    if(!root) {
        NODE* t = new NODE;
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(NODE* root) {
    if(root) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

NODE* get_max(NODE* r) {
    if(r && r->right){
        r=r->right;
    }
    return r;
}

NODE* get_min(NODE* r) {
    if(r && r->left){
        r=r->left;
    }
    return r;
}

NODE* del(NODE* root, int key) {
    if(!root) {
        return root;
    }
    if(root->data>key) {
        root->left = del(root->left, key);
    }
    else if(root->data<key) {
        root->right = del(root->right, key);
    }
    else {
        if(root->left == NULL && root->right==NULL) {
            delete root;
            return NULL;
        }
        if(root->left || root->right) {
            NODE* t = NULL;
            if(root->left)t = root->left;
            else if(root->right)t = root->right;
            delete root;
            return t;
        }
        NODE* max = get_max(root->left);
        root->data = max -> data;
        root->left = del(root->left, max->data);

        /*
        or 
            NODE* min = get_min(root->right);
            root->data = max -> data;
            root->right = del(root->right, min->data);
        */
    }
    return root;
}
int main(){
    int a[]= {20, 10, 5, 100, 55, 77, 99, 200};
    NODE* root=NULL;
    for(int i : a) {
        root = insert(root, i);
    }
    puts("BST:");
    inorder(root);
    puts("");

    puts("deleting 55");
    root=del(root, 55);
    inorder(root);
    puts("");

    puts("deleting 5");
    root=del(root, 5);
    inorder(root);
    puts("");

    return 0;
}
