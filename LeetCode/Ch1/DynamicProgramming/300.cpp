#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int dp[2502];
    int Len = nums.size();
    for(int i=0;i<Len;i++){
        dp[i] = 1;
    }
    for(int i=1;i<Len;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    for(int i=0;i<Len;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    return *max_element(dp,dp+Len);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums);

    return 0;
}