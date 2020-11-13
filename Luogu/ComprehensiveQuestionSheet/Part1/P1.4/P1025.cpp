#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int count_all=0;

void count(int n,int k,int c)
{
    if(n<k) return;
    if(k==1&&n>=c)
    {
        count_all++;
        return;
    }
    for(int i=c;i<=n-k+1;i++)
    {
        count(n-i,k-1,i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    count(n,k,1);
    cout<<count_all;
   

    return 0;
}

// TLE:找出所有情况，不同的就保存，超时
// 改进：直接从小到大分