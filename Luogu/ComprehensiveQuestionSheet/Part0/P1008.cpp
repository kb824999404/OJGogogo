#include <iostream>
#include <algorithm>


bool checkDiff3(int x,int y,int z)
{
    int x1=x/100,x2=(x%100)/10,x3=x%10;
    int y1=y/100,y2=(y%100)/10,y3=y%10;
    int z1=z/100,z2=(z%100)/10,z3=z%10;
    int array[9];
    array[0]=x1;
    array[1]=x2;
    array[2]=x3;
    array[3]=y1;
    array[4]=y2;
    array[5]=y3;
    array[6]=z1;
    array[7]=z2;
    array[8]=z3;
    std::sort(array,array+9);
    if(array[0]==0) return false;
    for(int i=0;i<8;i++)
    {
        if(array[i]==array[i+1])
            return false;
    }
    return true;
}

int main()
{
    int max=987;
    for(int i=123;i<=max;i++)
    {
        int j=i*2,k=i*3;
        if(k>max) break;
        if(checkDiff3(i,j,k))
            printf("%d %d %d\n",i,j,k);
    }
    return 0;
}