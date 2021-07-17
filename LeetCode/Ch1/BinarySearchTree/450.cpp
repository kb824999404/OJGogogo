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

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return nullptr;
    if(root->val==key){
        if(root->left==nullptr&&root->right==nullptr)   return nullptr;
        else if(root->right==nullptr)  return root->left;
        else if(root->left==nullptr) return root->right;
        else{
            TreeNode* p = root->right;
            while(p->left!=nullptr){
                p = p->left;
            }
            root->val = p->val;
            root->right = deleteNode(root->right,p->val);
        }
    }
    else if(root->val<key){
        root->right = deleteNode(root->right,key);
    }
    else{
        root->left = deleteNode(root->left,key);
    }
    return root;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}