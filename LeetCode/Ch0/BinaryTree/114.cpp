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

TreeNode* flatten_treverse(TreeNode* root){
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = nullptr;
    TreeNode* lastNode = root;
    if(left){
        root->right = left;
        lastNode = flatten_treverse(left);
        lastNode->left = nullptr;
        lastNode->right = nullptr;
    }
    if(right){
        lastNode->right = right;
        lastNode = flatten_treverse(right);
        lastNode->left = nullptr;
        lastNode->right = nullptr;
    }
    return lastNode;
}

void flatten(TreeNode* root) {
    if(root==nullptr) return;
    flatten_treverse(root);
}

// // 定义：将以 root 为根的树拉平为链表
// void flatten(TreeNode root) {
//     // base case
//     if (root == null) return;
    
//     flatten(root.left);
//     flatten(root.right);

//     /**** 后序遍历位置 ****/
//     // 1、左右子树已经被拉平成一条链表
//     TreeNode left = root.left;
//     TreeNode right = root.right;
    
//     // 2、将左子树作为右子树
//     root.left = null;
//     root.right = left;

//     // 3、将原先的右子树接到当前右子树的末端
//     TreeNode p = root;
//     while (p.right != null) {
//         p = p.right;
//     }
//     p.right = right;
// }

void Traverse(TreeNode* root){
    if(root){
        cout << root->val << endl;
        Traverse(root->left);
        Traverse(root->right);
    }
    else{
        cout << "NULL\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    TreeNode* left = new TreeNode( 2 , new TreeNode(3),new TreeNode(4) );
    TreeNode* right = new TreeNode( 5 , nullptr ,  new TreeNode(6) );
    TreeNode* root = new TreeNode( 1 , left , right );
    Traverse(root);
    cout<<"===============================\n";
    flatten(root);
    Traverse(root);

    return 0;
}