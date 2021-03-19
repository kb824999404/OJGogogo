#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX=5001;
int n,m;
pair<int,int> farmers[MAX];

bool cmp(const pair<int,int>& A,const pair<int,int>& B)
{
    return A.first<B.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin>>n>>m;
    int p,c;
    for(int i=0;i<m;i++){
        cin>>p>>c;
        farmers[i]  = pair<int,int>(p,c);
    }
    sort(farmers,farmers+m,cmp);
    int price = 0;
    for(int i=0;i<m;i++){
        if(n>farmers[i].second){
            n-=farmers[i].second;
            price+=farmers[i].second*farmers[i].first;
        }
        else
        {   
            price+=farmers[i].first*n;
            break;
        }
    }
    cout<<price;
    
    return 0;
}