#include <bits/stdc++.h>
using namespace std;


int memo[502][502]{0};

int dp(string word1, string word2,int i,int j){
    if(i==-1) return j+1;
    if(j==-1) return i+1;
    if(memo[i][j]!=0) return memo[i][j];
    int dis;
    if(word1[i]==word2[j]) 
        dis = dp(word1,word2,i-1,j-1);
    else
        dis = min(  dp(word1,word2,i-1,j-1), 
            min( dp(word1,word2,i-1,j) , dp(word1,word2,i,j-1)  )  ) + 1 ;
    memo[i][j] = dis;
    return dis;
    
}

int minDistance(string word1, string word2) {
    // return dp(word1,word2,word1.size()-1,word2.size()-1);
    int len1 = word1.size(),len2 = word2.size();
    for(int i=1;i<=len1;i++){
        memo[i][0] = i;
    }
    for(int j=1;j<=len2;j++){
        memo[0][j] = j;
    }
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(word1[i-1]==word2[j-1]) memo[i][j] = memo[i-1][j-1];
            else
                memo[i][j] = min( memo[i-1][j-1] , 
                    min( memo[i-1][j] , memo[i][j-1] ) ) + 1;
        }
    }
    return memo[len1][len2];
}

int minDistance2(string word1, string word2) {
    int len1 = word1.size(),len2 = word2.size();
    int memo2[2][502]{0};
    int cur_index = 0;
    for(int j=1;j<=len2;j++){
        memo2[0][j] = j;
    }
    for(int i=1;i<=len1;i++){
        cur_index = 1-cur_index;
        memo2[cur_index][0] = i;
        for(int j=1;j<=len2;j++){
            if(word1[i-1]==word2[j-1]) memo2[cur_index][j] = memo2[1-cur_index][j-1];
            else
                memo2[cur_index][j] = min( memo2[1-cur_index][j-1] , 
                    min( memo2[1-cur_index][j] , memo2[cur_index][j-1] ) ) + 1;
        }
    }
    return memo2[cur_index][len2];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cout << minDistance2("horse","ros");

    return 0;
}