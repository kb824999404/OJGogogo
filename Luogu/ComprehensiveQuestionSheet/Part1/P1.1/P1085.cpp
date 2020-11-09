#include <cstdio>
#include <cmath>

int main()
{
    int a,b,t=0,maxDay=0;
    for(int i=0;i<7;i++)
    {
        scanf("%d %d",&a,&b);
        if(a+b>maxDay)
        {
            maxDay=a+b;
            t=i+1;
        }
    }
    if(maxDay>8)
    {
        printf("%d",t);
    }
    else
    {
        printf("0");
    }
    
    return 0;
}