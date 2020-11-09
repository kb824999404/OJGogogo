#include <cstdio>
#include <cmath>

int main()
{
    int n;
    scanf("%d",&n);
    int a[3],b[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    int min=2<<25;
    for(int i=0;i<3;i++)
    {
        int c=ceil((float)n/a[i])*b[i];
        if(c<min)
            min=c;
    }
    printf("%d",min);
    return 0;
}
//WA:min初始值要足够大
