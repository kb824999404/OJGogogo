// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void backTrace(vector<int>& nums,vector<vector<int>>& res,vector<int>path,vector<bool>& visited,unsigned int depth){
    if(depth==nums.size()){
        res.push_back(path);
    }
    for(unsigned int i=0;i<nums.size();i++){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(nums[i]);
            backTrace(nums,res,path,visited,depth+1);
            visited[i] = false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int>path;
    vector<bool>visited;
    visited.resize(nums.size());
    for(unsigned int i=0;i<nums.size();i++){
        visited.push_back(false);
    }
    backTrace(nums,res,path,visited,0);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> res = permute(nums);
    for(unsigned int i=0;i<res.size();i++){
        for(unsigned int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}