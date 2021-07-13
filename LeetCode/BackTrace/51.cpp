// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isConflict(vector<string>& map,int n,int x,int y){
    for(int i=0;i<y;i++){
        if(map[i][x]=='Q') return true;
        if(x - (y-i)>=0 && map[i][x - (y-i)]=='Q') return true;
        if(x + (y-i)<n && map[i][x + (y-i)]=='Q') return true;
    }

    return false;
}

void backTrace(vector<vector<string>>& res,vector<string> map,int n,int depth){
    if(depth==n){
        res.push_back(map);
        return;
    }
    for(int i=0;i<n;i++){
        if(map[depth][i]=='.'){
            map[depth][i] = 'Q';
            if(!isConflict(map,n,i,depth)){
                backTrace(res,map,n,depth+1);
            }
            map[depth][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> map;
    for(int i=0;i<n;i++){
        string row = "";
        for(int j=0;j<n;j++){
            row += ".";
        }
        map.push_back(row);
    }
    backTrace(res,map,n,0);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    vector<vector<string>> res = solveNQueens(4);
    for(unsigned int i=0;i<res.size();i++){
        for(unsigned int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<res.size()<<endl;
    return 0;
}