#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    int dp[10];
    unsigned int N = nums.size();
    dp[0] = 0;
    dp[1] = nums[0];
    for(unsigned int i=2;i<=N;i++){
        dp[i] = max( dp[i-1],dp[i-2]+nums[i-1] );
    }
    return max(dp[N-1],dp[N]);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{2,7,9,3,1};
    cout << rob(nums) << endl;

    return 0;
}