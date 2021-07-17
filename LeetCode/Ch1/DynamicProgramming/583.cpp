#include <bits/stdc++.h>
using namespace std;



int minDistance(string word1, string word2) {
    int len1 = word1.size(),len2 = word2.size();
    int memo[2][502]{0};
    int cur_index = 0;
    for(int j=1;j<=len2;j++){
        memo[0][j] = j;
    }
    for(int i=1;i<=len1;i++){
        cur_index = 1-cur_index;
        memo[cur_index][0] = i;
        for(int j=1;j<=len2;j++){
            if(word1[i-1]==word2[j-1]) memo[cur_index][j] = memo[1-cur_index][j-1];
            else
                memo[cur_index][j] = min( memo[1-cur_index][j-1] + 2 , 
                    min( memo[1-cur_index][j] , memo[cur_index][j-1] ) + 1 );
        }
    }
    return memo[cur_index][len2];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cout << minDistance("sea","eat");

    return 0;
}