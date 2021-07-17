#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    int memo[100][100]{-1};
    for(int i=0;i<M;i++){
        memo[i][N] = INT_MAX;
    }
    for(int j=0;j<N;j++){
        memo[M][j] = INT_MAX;
    }
    memo[M-1][N-1] = grid[M-1][N-1]>=0?1:1-grid[M-1][N-1];
    for(int i=M-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(i==M-1&&j==N-1) continue;
            int res = min( memo[i+1][j] , memo[i][j+1] ) - grid[i][j];
            memo[i][j] = res<=0?1:res;
        }
    }
    return memo[0][0];

}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    auto grid = vector<vector<int>>{ {-2,-3,3},{-5,-10,1},{10,30,-5} };
    cout << calculateMinimumHP(grid);

    return 0;
}