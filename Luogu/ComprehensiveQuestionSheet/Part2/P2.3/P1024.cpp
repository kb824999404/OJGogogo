#include <iostream>
#include <cmath>
using namespace std;

float a,b,c,d;


float F(float x)
{
    return a*powf(x,3)+b*powf(x,2)+c*x+d;
}


float division(float x1,float x2)
{
    while(x2-x1>=0.001)
    {
        float x=(x1+x2)/2.0f;
        if(F(x)*F(x1)<0)
            x2=x;
        else
            x1=x;
    }
    return x1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin>>a>>b>>c>>d;

    int p=0;
    float A[3];

    for(int i=-100;i<100;i++)
    {
        if(F(i)==0)
        {
            A[p++] = i;
            if(p==3)    break;
        }
        else if(F(i)*F(i+1)<0)
        {
            A[p++] = division(i,i+1);
            if(p==3)    break;
        }
    }
    printf("%.2f %.2f %.2f",A[0],A[1],A[2]);
        

    return 0;
}