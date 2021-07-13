#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int coinChange(vector<int>& coins, int amount) {
    if(amount==0) return 0;
    if(amount<0) return -1;
    if(memo[amount-1]!=0) return memo[amount-1];
    int res = amount+1;
    for(unsigned int i=0;i<coins.size();i++){
        int subproblem = coinChange(coins,amount-coins[i]);
        if(subproblem<0) continue;
        res = min(res,subproblem+1);
    }
    if(res==amount+1) return -1;
    memo[amount-1] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int MAX = 1<<16;

    memo.resize(MAX);

    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    cout << coinChange(coins,11) << endl;

    return 0;
}