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

TreeNode* build(vector<int>& inorder,int inLeft,int inRight,
    vector<int>& postorder,int postLeft,int postRight){
        if(postLeft>postRight||inLeft>inRight) return nullptr;
        if(postLeft==postRight) return new TreeNode(postorder[postLeft]);
        if(inLeft==inRight) return new TreeNode(inorder[inLeft]);

        int value = postorder[postRight];
        int index;
        for(index=inLeft;index<=inRight;index++){
            if(inorder[index]==value) break;
        }
        TreeNode* root = new TreeNode(value);
        int leftNum = index-inLeft;
        root->left = build(inorder,inLeft,index-1,postorder,postLeft,postLeft+leftNum-1);
        root->right = build(inorder,index+1,inRight,postorder,postLeft+leftNum,postRight-1);

        return root;
        
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode* root = buildTree(preorder,inorder);

    return 0;
}