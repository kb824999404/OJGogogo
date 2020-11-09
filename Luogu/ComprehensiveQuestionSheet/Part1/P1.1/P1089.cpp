#include <cstdio>
#include <cmath>

int main()
{
    int a[12];
    for(int i=0;i<12;i++)
    {
        scanf("%d",&a[i]);
    }
    int n=0,r=0;
    bool noEnough=false;
    for(int i=0;i<12;i++)
    {
        n+=300;
        n-=a[i];
        if(n<0)
        {
            printf("%d",-(i+1));
            noEnough=true;
            break;
        }
        else if(n>=100)
        {
            int x=n-n%100;
            n=n%100;
            r+=x;
        }
    }
    if(!noEnough)
    {
        n+=ceil(r*1.2);
        printf("%d",n);
    }

    return 0;
}

// 第一次 WA:负数的出错??为啥有-7
// 第二次 AC:透支是输出月份，不是钱，没看清题意@_@
