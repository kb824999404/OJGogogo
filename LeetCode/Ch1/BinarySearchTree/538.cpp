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
int sum=0;

void Traverse(TreeNode* root){
    if(!root)   return;
    Traverse(root->right);
    sum+= root->val;
    root->val =sum;
    Traverse(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    Traverse(root);
    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}