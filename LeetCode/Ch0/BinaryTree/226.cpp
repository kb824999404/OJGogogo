#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void Traverse(TreeNode* root){
    cout << root->val << endl;
    if(root->left) Traverse(root->left);
    if(root->right) Traverse(root->right);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    TreeNode* left = new TreeNode( 7 , new TreeNode(9),new TreeNode(6) );
    TreeNode* right = new TreeNode( 2 , new TreeNode(3) ,  new TreeNode(1) );
    TreeNode* root = new TreeNode( 4 , left , right );
    Traverse(root);
    cout<<"===============================\n";
    root = invertTree(root);
    Traverse(root);

    return 0;
}