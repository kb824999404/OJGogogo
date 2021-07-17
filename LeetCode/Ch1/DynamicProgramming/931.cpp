#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int dp[10][10]{0};
    int rows=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        dp[i][0] = INT_MAX/2;
        dp[i][cols+1] = INT_MAX/2;
    }
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1],dp[i-1][j+1]) ) + matrix[i-1][j-1];
        }
    }
    int result=INT_MAX;
    for(int j=1;j<=cols;j++){
        result = min(result,dp[rows][j]);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    // vector<vector<int>> matrix{ {2,1,3},{6,5,4},{7,8,9} };
    vector<vector<int>> matrix{ {-48} };
    cout << minFallingPathSum(matrix);

    return 0;
}