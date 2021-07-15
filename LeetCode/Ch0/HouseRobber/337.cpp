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
unordered_map<TreeNode*,int> memo;


int rob(TreeNode* root) {
    if(!root) return 0;
    if(memo.count(root))
        return memo[root];
    int do_it = root->val + ( (root->left)? rob(root->left->left)+rob(root->left->right) :0 )
        + ( (root->right)? rob(root->right->left)+rob(root->right->right) :0 );
    int no_do = rob(root->left) + rob(root->right);

    int res = max(do_it,no_do);
    memo[root] = res;

    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    TreeNode* root = new TreeNode( 3, new TreeNode(2,nullptr,new TreeNode(3)),
        new TreeNode( 3,nullptr, new TreeNode(1) ) );
    cout << rob(root) << endl;

    return 0;
}