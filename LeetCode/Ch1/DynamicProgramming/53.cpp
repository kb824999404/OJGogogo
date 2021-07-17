#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int dp[30002]{0};
    int Len = nums.size();
    for(int j=1;j<=Len;j++){
        dp[j] = max( dp[j-1], 0 ) + nums[j-1];
    }
    return *max_element(dp+1,dp+Len+1);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto nums = vector<int>{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);

    return 0;
}