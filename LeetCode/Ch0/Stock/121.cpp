#include <bits/stdc++.h>

using namespace std;

// const int N = 100001;

// int maxProfit(vector<int>& prices) {
//     int dp[N][2];
//     dp[0][0] = 0;
//     dp[0][1] = -INT_MAX;
//     unsigned int day = prices.size();
//     for(unsigned int i=1;i<=day;i++){
//         dp[i][0] = max( dp[i-1][0] , dp[i-1][1] + prices[i-1] );
//         dp[i][1] = max( dp[i-1][1] , - prices[i-1] );
//     }
//     return dp[day][0];
// }

int maxProfit(vector<int>& prices) {
    int dp_0=0,dp_1=-INT_MAX;
    unsigned int day = prices.size();
    for(unsigned int i=1;i<=day;i++){
        dp_0 = max( dp_0 , dp_1 + prices[i-1] );
        dp_1 = max( dp_1 , - prices[i-1] );
    }
    return dp_0;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> prices{7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;

    return 0;
}