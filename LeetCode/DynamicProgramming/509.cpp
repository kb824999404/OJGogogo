#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
    if(n==0) return 0;
    if(n==1)    return 1;
    int f1=0,f2=1,f3;
    for(int i=1;i<n;i++){
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;

}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    for(int i=1;i<10;i++){
        cout<<fib(i)<<endl;
    }
    
    return 0;
}