#include <bits/stdc++.h>
// #include <iostream>
// #include <deque>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
typedef pair<int,TreeNode*> P;


int minDepth(TreeNode* root) {
    int depth = INT_MAX;
    deque<P> q;
    q.push_back(P(1,root));
    while(!q.empty()){
        P p =  q.back(); 
        q.pop_back();
        int d = p.first;
        TreeNode* node = p.second;
        if(!node->left&&!node->right){
            depth = min(depth,d);
            continue;
        }
        if(node->left){
            q.push_back(P(d+1,node->left));
        }
        if(node->right){
            q.push_back(P(d+1,node->right));
        }
    }

    return depth;        
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    TreeNode* right = new TreeNode(20,new TreeNode(15),new TreeNode(7));
    TreeNode* left = new TreeNode(9);
    TreeNode* root = new TreeNode(3,left,right);

    cout << minDepth(root);


    return 0;
}
