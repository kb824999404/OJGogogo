#include <cstdio>
#include <cmath>

bool hasSum(int *array,int n,int target)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(target==array[i]+array[j])   return true;
        }
    }
    return false;
}

int main()
{
    int array[100],n,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(hasSum(array,n,array[i]))    count++;
    }
    printf("%d",count);

    return 0;
}