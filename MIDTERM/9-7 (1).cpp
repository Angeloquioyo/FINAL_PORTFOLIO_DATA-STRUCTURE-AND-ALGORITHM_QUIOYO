#include <iostream>
using namespace std;

struct TreeNode {
    int data;            
    TreeNode* left;     
    TreeNode* right;      
};

TreeNode* create(int value) {
    TreeNode* node = new TreeNode();
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL)
        return create(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = NULL;
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    int size = sizeof(values) / sizeof(values[0]);

    cout << "Inserting values into the Binary Search Tree:\n";
    for (int i = 0; i < size; i++) {
        cout << values[i] << " ";
        root = insert(root, values[i]);
    }

    cout << "\n\nTree Traversals:\n";
    cout << "In-order Traversal (L, Root, R): ";
    inorder(root);
    cout << "\nPre-order Traversal (Root, L, R): ";
    preorder(root);
    cout << "\nPost-order Traversal (L, R, Root): ";
    postorder(root);
    cout << "\n";

    return 0;
}
