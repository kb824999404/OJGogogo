#include <bits/stdc++.h>

using namespace std;

int maxProfit(unsigned int k,vector<int>& prices) {
    int dp[101][2];
    for(unsigned i=0;i<=k;i++){
        dp[i][0] = -INT_MAX;
        dp[i][1] = -INT_MAX;
    }
    dp[0][0] = 0;
    unsigned int day = prices.size();
    for(unsigned int i=1;i<=day;i++){
        for(unsigned int j=1;j<=k;j++){
            dp[j][0] = max( dp[j][0] , dp[j][1] + prices[i-1] );
            dp[j][1] = max( dp[j][1] , dp[j-1][0] - prices[i-1] );
        }
    }
    int result = -INT_MAX;
    for(unsigned i=0;i<=k;i++){
        result = max(result,dp[i][0]);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> prices{7,6,4,3,1};
    cout << maxProfit(2,prices) << endl;

    return 0;
}