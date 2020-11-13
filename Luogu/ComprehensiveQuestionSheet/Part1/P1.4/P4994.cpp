#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int M,n=0;
    cin>>M;
    int f1=0,f2=1,f3;
    while(true)
    {
        f3=(f1+f2)%M;
        f1=f2;
        f2=f3;
        n++;
        if(f1%M==0&&f2%M==1)
            break;
    }
    cout<<n;

    return 0;
}

// WA:数太大,long long int
// 大于M才开始取模
// 相加的数直接取模