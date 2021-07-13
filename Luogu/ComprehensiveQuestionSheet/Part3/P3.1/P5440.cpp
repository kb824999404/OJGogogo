#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
int T;
char date[10];
int num=0;


bool is_prime(int n){
    for(int i=2;i*i<n;i++){
        if(n%i==0)  return false;
    }
    return true;
}

void solve(){
    int n;
    if(date[8-1]!='-'&&date[8-2]!='-'){
        n=(date[8-1]-'0')+(date[8-2]-'0')*10;
        if(is_prime(n))
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>date;
        num=0;
        solve();
        cout<<num<<endl;
    }

    return 0;
}