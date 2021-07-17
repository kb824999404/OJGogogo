#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int f0=0,f1=1,f2;
    for(int i=1;i<n;i++){
        f2 = f0+f1;
        f0=f1;
        f1=f2;
    }
    return f2;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cout<<fib(4);

    return 0;
}