#include <bits/stdc++.h>
using namespace std;

bool can = false;

void BackTrack(vector<int>& nums,int index,int delta){
    if(index == nums.size()){
        can |= delta==0;
        return;
    }
    BackTrack(nums,index+1,delta+nums[index]);
    BackTrack(nums,index+1,delta-nums[index]);
}

bool canPartition(vector<int>& nums) {
    int Len = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2!=0) return false;
    sum /= 2;
    bool dp[10001]{false};
    dp[0] = true;
    for(int i=1;i<=Len;i++)
        for(int j=sum;j>=0;j--)
            if(j>=nums[i-1]) dp[j] = dp[j] || dp[j-nums[i-1]];

    return dp[sum];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto nums = vector<int>{1,5,11,5};
    cout << canPartition(nums);

    return 0;
}