#include <bits/stdc++.h>

using namespace std;

int robRange(vector<int>& nums,int start,int end){
    int dp[102];
    dp[start] = 0;
    dp[start+1] = nums[start];
    for(int i=start+1;i<=end;i++){
        dp[i+1] = max( dp[i],dp[i-1]+nums[i] );
    }

    return max(dp[end+1],dp[end]);
}

int rob(vector<int>& nums) {
    int N = nums.size();
    if(N==1) return nums[0];
    if(N==2) return max(nums[0],nums[1]);
    return max( robRange(nums,0,N-2),robRange(nums,1,N-1) );
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{1,2,3,1};
    cout << rob(nums) << endl;

    return 0;
}