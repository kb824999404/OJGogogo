#include <cstdio>
#include <cmath>

int main()
{
    int h[10],arm,chair=30;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&h[i]);
    }
    scanf("%d",&arm);
    int max=arm+chair,count=0;
    for(int i=0;i<10;i++)
    {
        if(h[i]<=max)   count++;
    }
    printf("%d",count);
    return 0;
}