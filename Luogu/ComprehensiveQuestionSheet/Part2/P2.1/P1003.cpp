#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
#define N 10001

void solve1()
{
    int n,a,b,g,k;
    int map[MAX][MAX];
    memset(map,-1,sizeof(map));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>g>>k;
        for(int x=a;x<a+g;x++)
        {
            for(int y=b;y<b+k;y++)
            {
                map[x][y]=i+1;
            }
        }
    }
    cin>>a>>b;
    cout<<map[a][b];
}
void solve2()
{
    int n,x,y,top=-1;
    int blankets[N][4];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
            cin>>blankets[i][j];
    }
    cin>>x>>y;
    for(int i=0;i<n;i++)
    {
        int a=blankets[i][0],b=blankets[i][1],g=blankets[i][2],k=blankets[i][3];
        if(x>=a&&x<=a+g&&y>=b&&y<=b+k)
            top=i+1;
    }
    cout<<top;

}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    solve2();


    return 0;
}

// 第一种：直接模拟，RE
// 第二种：读入所有毛毯，只计算目标点