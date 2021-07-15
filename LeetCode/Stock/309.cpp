#include <bits/stdc++.h>

using namespace std;


int maxProfit(vector<int>& prices) {
    int dp_0=-prices[0]; //买入股票状态
    int dp_1=0; //卖出股票状态，已过冷冻期
    int dp_2=0; //今天卖出股票状态
    int dp_3=0; //冷冻期
    unsigned int day = prices.size();
    for(unsigned int i=0;i<day;i++){
        int dp_0_new,dp_1_new,dp_2_new,dp_3_new;
        dp_0_new = max(dp_0,max(dp_1,dp_3)-prices[i]);
        dp_1_new = max(dp_1, dp_3);
        dp_2_new = dp_0 + prices[i];
        dp_3_new = dp_2;
        dp_0 = dp_0_new;
        dp_1 = dp_1_new;
        dp_2 = dp_2_new;
        dp_3 = dp_3_new;
    }
    return max(max( dp_1 ,dp_2),dp_3);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> prices{1};
    cout << maxProfit(prices) << endl;

    return 0;
}