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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==nullptr){
        return new TreeNode(val);
    }
    if(root->val>val){
        root->left = insertIntoBST(root->left,val);
    }
    else if(root->val<val){
        root->right = insertIntoBST(root->right,val);
    }
    return root;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}