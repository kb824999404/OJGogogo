#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int N;
long long C,weights[MAX],sum[MAX],weight_max = 0;


void dfs(int depth,long long weight_cur){
    if(weight_cur+sum[depth]<=weight_max)   return;
    if(weight_cur>weight_max)
        weight_max=weight_cur;
    if(depth<0){
        return;
    }
    if(weight_cur+weights[depth]<=C){
        dfs(depth-1,weight_cur+weights[depth]);
    }
    dfs(depth-1,weight_cur);
}



int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>N>>C;

    for(int i=0;i<N;i++){
        cin>>weights[i];
        if(i==0)    sum[0] = weights[i];
        else    sum[i] = sum[i-1] + weights[i];
    }
    dfs(N-1,0);
    printf("%lld",weight_max);


    return 0;
}

//第一次：DFS，TLE
//第二次：0剪支
//第三次：从后往前搜索,TLE
//第四次：前缀和剪支,TLE
//第五次：先搜1再搜0，AC