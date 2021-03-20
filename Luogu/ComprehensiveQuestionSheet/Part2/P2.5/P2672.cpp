#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> PI;
const int MAX=100001;
PI houses[MAX];

bool cmp(const PI&A , const PI& B){
    return A.second>B.second;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin>>n;
    int distance,cost;
    for(int i=1;i<=n;i++){
        cin>>distance;
        houses[i] = PI(distance,0);
    }
    for(int i=1;i<=n;i++){
        cin>>cost;
        houses[i].second = cost;
    }
    sort(houses+1,houses+n+1,cmp);
    int sum[MAX]={0},q[MAX]={0},h[MAX]={0};
    for(int i=1;i<=n;i++)    sum[i]=sum[i-1]+houses[i].second;
    for(int i=1;i<=n;i++)    q[i]=max(q[i-1],2*houses[i].first);    //前i个最大值
    for(int i=n;i>=1;i--)  h[i]=max(h[i+1],2*houses[i].first+houses[i].second); //后i个最大值
    for(int i=1;i<=n;i++)    cout<<max(sum[i]+q[i],sum[i-1]+h[i])<<endl;
    return 0;
}

//题解：https://www.luogu.com.cn/blog/Rainy7/solution-p2672