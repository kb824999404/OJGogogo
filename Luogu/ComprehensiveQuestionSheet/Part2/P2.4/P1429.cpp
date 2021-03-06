#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL MAX = 2e5+1;
const LL INF = 2e10;

struct _Point
{
    LL x;
    LL y;
};
typedef struct _Point Point;

Point points[MAX];
LL n;
LL tmp[MAX];

bool cmp(const Point& x,const Point& y)
{
    if(x.x==y.x)    return x.y < y.y;
    else    return x.x < y.x;
}
bool cmps(LL x,LL y)
{
    return points[x].y < points[y].y;
}

double dist(LL x,LL y)
{
    LL dx = points[x].x - points[y].x;
    LL dy = points[x].y - points[y].y; 
    return sqrtl(dx*dx+dy*dy);
}

double merge(LL l, LL r)
{
    if(l>=r)    return INF;
    if(l+1==r)   return dist(l,r);
    LL mid = (l+r)/2;
    double d1 = merge(l,mid);
    double d2 = merge(mid+1,r);
    double dd = min(d1,d2);
    LL i,j=0,k=0;
    for(i=l;i<=r;i++)
    {
        if(fabs(points[mid].x-points[i].x)<dd)
            tmp[k++] = i;
    }
    sort(tmp,tmp+k,cmps);
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k&&points[tmp[i]].y-points[tmp[j]].y<dd;j++)
        {
            double dk = dist(tmp[i],tmp[j]);
            if(dk<dd)
                dd=dk;
        }
    }
    return dd;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    cin>>n;
    LL x,y;
    for(LL i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
    }
    sort(points,points+n,cmp);
    printf("%.4lf",merge(0,n-1));
    return 0;
}