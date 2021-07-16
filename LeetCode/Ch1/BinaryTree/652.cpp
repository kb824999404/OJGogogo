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

vector<TreeNode*> duplicateSubtrees;
unordered_map<string,int> subtreeMap;

string traverse(TreeNode* root){
    if(root==nullptr) return "#";
    string str="";
    str += traverse(root->left);
    str += traverse(root->right);
    str += "("+to_string(root->val)+")";
    if(subtreeMap.count(str)&&subtreeMap[str]==1)
        duplicateSubtrees.push_back(root);
    subtreeMap[str]++;
    return str;
        
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    cout << traverse(root) <<endl;
    return duplicateSubtrees;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};

    return 0;
}