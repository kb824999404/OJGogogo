#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;


LL div_mod(LL b,LL p,LL k)
{
    LL s=1;
    if(p==0)
    {
        s=1%k;
    }
    else if(p==1)
    {
        s = b%k;
    }
    else
    {
        if(p%2==0)
        {
            LL p1=p/2;
            LL bp = div_mod(b,p1,k)%k;
            s = (bp*bp)%k;
        }
        else
        {
            LL p1=(p-1)/2;
            LL bp = div_mod(b,p1,k)%k;
            s = (bp*bp)%k;
            s *= (b%k);
            s %=k;
        }
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    LL b,p,k,s;
    cin>>b>>p>>k;
    s = div_mod(b,p,k);

    printf("%lld^%lld mod %lld=%lld",b,p,k,s);

    return 0;
}
//第一次：不分奇偶直接拆两半
//第二次：奇数时减一变偶数，再拆成两半，一个WA
//第三次：考虑p为0时，AC
