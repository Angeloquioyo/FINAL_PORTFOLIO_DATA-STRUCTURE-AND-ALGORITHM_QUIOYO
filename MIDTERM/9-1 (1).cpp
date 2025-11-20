#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    char data;
    vector<TreeNode*> children;

    TreeNode(char val) {
        data = val;
    }
};

TreeNode* createNode(char val) {
    return new TreeNode(val);
}

void computeDepths(TreeNode* root, vector<pair<char, int>>& depths) {
    if (!root) return;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int depth = q.front().second;
        q.pop();

        depths.push_back({current->data, depth});

        for (TreeNode* child : current->children) {
            q.push({child, depth + 1});
        }
    }
}

int computeHeights(TreeNode* node, vector<pair<char, int>>& heights) {
    if (!node) return -1;

    int maxChildHeight = -1;

    for (TreeNode* child : node->children) {
        int childHeight = computeHeights(child, heights);
        if (childHeight > maxChildHeight) {
            maxChildHeight = childHeight;
        }
    }

    int height = maxChildHeight + 1;
    heights.push_back({node->data, height});
    return height;
}

int main() {
    TreeNode* A = createNode('A');
    TreeNode* B = createNode('B');
    TreeNode* C = createNode('C');
    TreeNode* D = createNode('D');
    TreeNode* E = createNode('E');
    TreeNode* F = createNode('F');
    TreeNode* G = createNode('G');
    TreeNode* H = createNode('H');
    TreeNode* I = createNode('I');
    TreeNode* J = createNode('J');
    TreeNode* K = createNode('K');
    TreeNode* L = createNode('L');
    TreeNode* M = createNode('M');
    TreeNode* N = createNode('N');
    TreeNode* P = createNode('P');
    TreeNode* Q = createNode('Q');

    A->children = {B, C, D, E, F, G};
    D->children = {H};
    E->children = {I, J};
    J->children = {P, Q};
    F->children = {K, L, M};
    G->children = {N};

    vector<pair<char, int>> depths;
    vector<pair<char, int>> heights;

    computeDepths(A, depths);
    computeHeights(A, heights);

    sort(depths.begin(), depths.end());
    sort(heights.begin(), heights.end());

    cout << "Node\tHeight\tDepth\n";
    for (char ch = 'A'; ch <= 'Q'; ++ch) {
        if (ch == 'O') continue; 

        int depth = -1, height = -1;

        for (auto& d : depths)
            if (d.first == ch) depth = d.second;

        for (auto& h : heights)
            if (h.first == ch) height = h.second;

        cout << ch << "\t" << height << "\t" << depth << "\n";
    }

    return 0;
}
