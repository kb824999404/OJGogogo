#include <bits/stdc++.h>
using namespace std;

int counter=0;

void backTrack(vector<int>& nums,int target,int index,int sum){
    if(index==nums.size()){
        if(sum==target) counter++;
        return;
    }
    backTrack(nums,target,index+1,sum-nums[index]);
    backTrack(nums,target,index+1,sum+nums[index]);
}

unordered_map<string,int> memo;

int dp(vector<int>& nums,int target,int index,int sum,string key){
    if(index==nums.size()){
        if(sum==target) return 1;
        else return 0;
    }
    if(memo.count(key))
        return memo[key];
    int c = dp(nums,target,index+1,sum-nums[index],key+"-") +
        dp(nums,target,index+1,sum+nums[index],key+"+");
    memo[key] = c;
    return c;
}

int findTargetSumWays(vector<int>& nums, int target) {
    // backTrack(nums,target,0,0);
    // return counter;
    return dp(nums,target,0,0,"#");
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    vector<int> nums{1,1,1,1,1};
    cout << findTargetSumWays(nums,3);
    return 0;
}