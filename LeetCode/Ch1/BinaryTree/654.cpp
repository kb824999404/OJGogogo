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

TreeNode* construct(vector<int>& nums,int start,int end){
    if(start>end) return nullptr;
    if(start==end) return new TreeNode(nums[start]);
    int n_max=0,index_max=0;;
    for(int i=start;i<=end;i++){
        if(nums[i]>n_max){
            n_max = nums[i];
            index_max = i;
        }
    }
    TreeNode* root = new TreeNode(n_max);
    if(start<=index_max-1)
        root->left = construct(nums,start,index_max-1);
    if(end>=index_max+1)
        root->right = construct(nums,index_max+1,end);
    
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums,0,nums.size()-1);
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);

    return 0;
}