#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(),envelopes.end(),
        [](vector<int>& x,vector<int>& y){
            if(x[0]<y[0]) return true;
            else if(x[0]>y[0]) return false;
            else return x[1]<y[1];
    });
    int dp[5002];
    int Len = envelopes.size();
    for(int i=0;i<Len;i++){
        dp[i] = 1;
    }
    for(int i=1;i<Len;i++){
        for(int j=0;j<i;j++){
            if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                dp[i] = max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp,dp+Len);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    auto envelopes = vector<vector<int>>{{5,4},{6,4},{6,7},{2,3}};
    cout << maxEnvelopes(envelopes);

    return 0;
}