#include <iostream>
#include <cstdio>
#include <cstring>

int getSameCount(char* targetLine,int n1,char* inputLine,int n2)
{
    int sameCount=0;
    for(int i=0,j=0;i<n1||j<n2;)
    {
        if(i>=n1)
        {
            if(inputLine[j]=='<')
            {
                i--;
            }
            j++;
            continue;
        }
        if(targetLine[i]==inputLine[j])
        {
            sameCount++;
            i++;
        }
        else if(inputLine[j]=='<')
        {
            i--;
        }
        else
        {
            i++;
        }
        j++;
        
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
    int KPM=(double)countSame/((double)T/60);
    printf("%d",KPM);

    return 0;
}

// 读取一行:cin.getline