#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    if(M==1&&N==1) return grid[0][0];
    int Cost[2][100]{0};
    int cur_index = 0;
    {
        Cost[cur_index][0] = grid[0][0]; 
        for(int j=1;j<N;j++){
            Cost[cur_index][j] = Cost[cur_index][j-1] +  grid[0][j];
        }
    }
    for(int i=1;i<M;i++){
        cur_index = 1 - cur_index;
        Cost[cur_index][0] = Cost[1-cur_index][0] + grid[i][0];
        for(int j=1;j<N;j++){
            Cost[cur_index][j] = min(Cost[cur_index][j-1],Cost[1-cur_index][j]) + grid[i][j];
        }
    }
    return Cost[cur_index][N-1];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    auto grid = vector<vector<int>>{ {1,2,3},{4,5,6} };
    cout << minPathSum(grid);

    return 0;
}