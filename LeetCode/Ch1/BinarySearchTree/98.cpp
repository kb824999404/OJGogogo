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
int curVal=INT_MIN;
int counter=0;
bool isValid=true;
void Traverse(TreeNode* root){
    if(root==nullptr) return;
    Traverse(root->left);
    if(root->val<=curVal)    isValid=false;
    if(counter==0){
        isValid = true;
        counter=1;
    }
    curVal=root->val;
    Traverse(root->right);
}

bool isValidBST(TreeNode* root) {
    Traverse(root);
    return isValid;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}