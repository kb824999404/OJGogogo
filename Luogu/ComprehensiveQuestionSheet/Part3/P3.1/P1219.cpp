#include <bits/stdc++.h>
using namespace std;
const int MAX=15;
int chess[MAX]={-1};
bool visited[MAX]={false};
int n;
int solve=0;

bool placeTest(int depth){
    for(int i=0;i<depth-1;i++){
        if(abs(chess[depth]-chess[i])==abs(depth-i)||chess[depth]+chess[i]==depth+i)
            return false;
    }
    return true;
}


void search(int depth){
    if(depth>=n){
        solve++;
        if(solve<4){
            for(int i=0;i<n;i++){
                cout<<chess[i]+1<<' ';
            }
            cout<<endl;
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            chess[depth]=i;
            visited[i]=true;
            if(placeTest(depth)){
                search(depth+1);
            }
            chess[depth]=-1;
            visited[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>n;
    search(0);
    cout<<solve;
    return 0;
}