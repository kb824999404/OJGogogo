#include <cstdio>
#include <cstring>

int main()
{
    int count=0;
    char str[10];
    while (true)
    {
        int x=scanf("%s",str);
        if(x<=0||strlen(str)<=0)  break;
        else count+=strlen(str);
    }
    printf("%d",count);
    return 0;
}

// 利用scanf返回值：正确匹配的参数个数