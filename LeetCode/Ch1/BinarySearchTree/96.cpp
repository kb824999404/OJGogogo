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

unordered_map<string,int> memo;

int num(int start,int end){
    if(start>end) return 1;
    string key = to_string(start)+"_"+to_string(end);
    if(memo.count(key)) return memo[key];
    int sum=0;
    for(int i=start;i<=end;i++){
        sum+= num(start,i-1)*num(i+1,end);
    }
    memo[key] = sum;
    return sum;
}

int numTrees(int n) {
    return num(0,n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    return 0;
}