#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char val;
    vector<Node*> child;
};

Node* makeNode(char v) {
    Node* n = new Node();
    n->val = v;
    return n;
}

void pre(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    for (auto c : root->child)
        pre(c);
}

void post(Node* root) {
    if (!root) return;
    for (auto c : root->child)
        post(c);
    cout << root->val << " ";
}

void in(Node* root) {
    if (!root) return;
    if (!root->child.empty())
        in(root->child[0]);
    cout << root->val << " ";
    for (int i = 1; i < root->child.size(); i++)
        in(root->child[i]);
}

bool find(Node* root, char key) {
    if (!root) return false;
    if (root->val == key) {
        cout << key << " was found!" << endl;
        return true;
    }
    for (auto c : root->child)
        if (find(c, key)) return true;
    return false;
}

int main() {
    Node* A = makeNode('A');
    Node* B = makeNode('B');
    Node* C = makeNode('C');
    Node* D = makeNode('D');
    Node* E = makeNode('E');
    Node* F = makeNode('F');
    Node* G = makeNode('G');
    Node* H = makeNode('H');
    Node* I = makeNode('I');
    Node* J = makeNode('J');
    Node* K = makeNode('K');
    Node* L = makeNode('L');
    Node* M = makeNode('M');
    Node* N = makeNode('N');
    Node* P = makeNode('P');
    Node* Q = makeNode('Q');
    Node* O = makeNode('O');

    A->child = {B, C, D, E, F, G};
    D->child = {H};
    E->child = {I, J};
    J->child = {P, Q};
    F->child = {K, L, M};
    G->child = {N, O}; // added new node O

    cout << "Pre-order: ";
    pre(A);
    cout << "\nPost-order: ";
    post(A);
    cout << "\nIn-order: ";
    in(A);

    cout << "\n\nFinding node O...\n";
    find(A, 'O');

    return 0;
}
