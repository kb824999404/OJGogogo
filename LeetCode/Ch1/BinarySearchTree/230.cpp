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

int counter = 0;
int val;

void Traverse(TreeNode* root, int k){
    if(!root)   return;
    Traverse(root->left,k);
    counter++;
    if(counter==k){
        val = root->val;
        return;
    }
    Traverse(root->right,k);
}

int kthSmallest(TreeNode* root, int k) {
    Traverse(root,k);
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}