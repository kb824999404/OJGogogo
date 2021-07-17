#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    int Len = coins.size();
    int dp[100]{1};
    for(int i=1;i<=Len;i++){
        for(int j=1;j<=amount;j++){
            if(j>=coins[i-1])
                dp[j] +=  dp[j-coins[i-1]];
        }
    }

    return dp[amount];
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto coins = vector<int>{1,2,5};
    cout << change(5,coins);

    return 0;
}