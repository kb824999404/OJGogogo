#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX=301;
int hs[MAX];

bool cmp(int A,int B){
    return A>B;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>hs[i];
    }
    sort(hs,hs+n,cmp);
    int x1=0,x2=n-1;
    long value=0;
    for(int i=0;i<n;i++){
        if(i==0){
            value+=hs[0]*hs[0];
        }
        else
        {
            // printf("x1:%d\tx2:%d\n",x1,x2);
            value+=pow(hs[x2]-hs[x1],2);
            x1=x2;
            x2=n-x2;
            if(i%2==0)
                x2-=1;
        }

    }    
    cout<<value;
    return 0;
}

//第一次：一半AC，一半WA
//第二次：value变long，AC