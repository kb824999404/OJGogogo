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

TreeNode* build(vector<int>& preorder,int preLeft,int preRight, 
    vector<int>& inorder,int inLeft,int inRight){
        if(preLeft>preRight||inLeft>inRight) return nullptr;
        if(preLeft==preRight) return new TreeNode(preorder[preLeft]);
        if(inLeft==inRight) return new TreeNode(inorder[inLeft]);

        int value = preorder[preLeft];
        int index;
        for(index=inLeft;index<=inRight;index++){
            if(inorder[index]==value) break;
        }
        TreeNode* root = new TreeNode(value);
        int leftNum = index-inLeft;
        root->left = build(preorder,preLeft+1,preLeft+leftNum,inorder,inLeft,index-1);
        root->right = build(preorder,preLeft+leftNum+1,preRight,inorder,index+1,inRight);

        return root;
        
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode* root = buildTree(preorder,inorder);

    return 0;
}