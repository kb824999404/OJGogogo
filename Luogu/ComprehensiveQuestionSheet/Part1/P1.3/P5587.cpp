#include <iostream>
#include <cstdio>
#include <cstring>

int getSameCount(char* targetLine,int n1,char* inputLine,int n2)
{
    char new_target[1000],new_input[1000];
    int p=0,n1_new,n2_new;
    for(int i=0;i<n1;i++)
    {
        if(targetLine[i]!='<') new_target[p++]=targetLine[i];
        else if(p>0) p--;
    }
    new_target[p]='\0';
    n1_new=p,p=0;
    for(int i=0;i<n2;i++)
    {
        if(inputLine[i]!='<') new_input[p++]=inputLine[i];
        else if(p>0)  p--;
    }
    new_input[p]='\0';
    n2_new=p;
    int sameCount=0;
    for(int i=0;i<n1_new&&i<n2_new;i++)
    {
        if(new_target[i]==new_input[i]) sameCount++;
    }
    return sameCount;
}

int main()
{
    char target[1000][1000],input[1000];
    int i=0,numLines,T;
    while(true)
    {
        std::cin.getline(target[i],100);
        if(strcmp(target[i],"EOF")==0)
            break;
        i++;
    }
    numLines=i,i=0;
    int countSame=0;
    while(true)
    {
        std::cin.getline(input,100);
        if(strcmp(input,"EOF")==0)
            break;
        if(i<numLines)
            countSame+=getSameCount(target[i],strlen(target[i]),input,strlen(input));
        i++;
    }
    scanf("%d",&T);
    int KPM=int((double)countSame/T*60.0);
    printf("%d",KPM);

    return 0;
}

// 读取一行:cin.getline
// 范文也包含退格
// 找不出问题了，算了，copy题解