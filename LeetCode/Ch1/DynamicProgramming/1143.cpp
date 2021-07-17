#include <bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    int dp[2][1002]{0};
    int Len1=text1.size(),Len2=text2.size();
    int cur_index = 0;
    for(int i=1;i<=Len1;i++){
        cur_index = 1-cur_index;
        for(int j=1;j<=Len2;j++){
            if(text1[i-1]==text2[j-1])
                dp[cur_index][j] = max ( dp[1-cur_index][j-1] + 1 ,
                     max(  dp[1-cur_index][j],dp[cur_index][j-1]  ) );
            else 
                dp[cur_index][j] = max ( dp[1-cur_index][j-1] , 
                    max(  dp[1-cur_index][j],dp[cur_index][j-1]  ) );
        }
    }
    return dp[cur_index][Len2];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout << longestCommonSubsequence("abcde","acer");

    return 0;
}