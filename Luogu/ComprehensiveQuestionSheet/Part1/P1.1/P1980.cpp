#include <cstdio>

int count(int n,int x)
{
    int i=0;
    while(n>0)
    {
        int j=n%10;
        if(j==x)    i++;
        n=n/10;
    }
    return i;
}

int main()
{
    int n,x,c=0;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        c+=count(i,x);
    }
    printf("%d",c);
    return 0;
}