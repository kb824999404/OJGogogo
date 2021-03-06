#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
typedef long long LL;

LL logs[MAX];
int l;
LL k;
LL result_min = 10e9+1 , result_max = 0;


LL getMax()
{
    LL max = 0;
    for(int i=0;i<l;i++)
    {
        if(logs[i]>0&&logs[i]>max)
            max = logs[i];
        else if(-logs[i]>max)
            max = -logs[i];
    }
    return max;
}

int justify(LL n)
{
    LL cur_code=0,cur_k=0;
    for(int i=0;i<l;i++)
    {
        cur_code +=logs[i];
        if(cur_code>=n)
        {
            cur_k++;
            cur_code = 0;
        }
        else if(cur_code<0)
            cur_code = 0;
    }
    return cur_k-k;
}

// void solve(LL n0,LL n1)
// {
//     if(n0>n1)  return;    
//     int j0=justify(n0),j1=justify(n1);
//     if(n0==n1)
//     {
//         if(j0==0)
//         {
//             if(n1>result_max)
//                 result_max = n1;
//             if(n0<result_min)
//                 result_min = n0;
//         }
//         return;
//     }
//     if(j0*j1<0) //一个小一个大
//     {
//         LL mid = (n0+n1)/2;
//         solve(n0,mid);
//         solve(mid+1,n1);
//     }
//     else if(j0==0&&j1==0)   //两个都是
//     {
//         if(n1>result_max)
//             result_max = n1;
//         if(n0<result_min)
//             result_min = n0;
//     }
//     else if(j0==0&&j1<0)    //左边是，右边小
//     {
//         if(n0<result_min)
//             result_min = n0;
//         LL mid = (n0+n1)/2;
//         solve(n0,mid);
//         solve(mid+1,n1);
//     }
//     else if(j0>0&&j1==0)    //左边大，右边是
//     {
//         if(n1>result_max)
//             result_max = n1;
//         LL mid = (n0+n1)/2;
//         solve(n0,mid);
//         solve(mid+1,n1);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(NULL);

//     cin>>l>>k;
//     for(int i=0;i<l;i++)
//     {
//         cin>>logs[i];
//     }
//     LL n_max = getMax();
//     LL n0 = 1;
//     LL n1 = n_max;
//     solve(n0,n1);
//     if(result_min == 10e9+1&&result_max==0)
//         cout<<-1;
//     else if(result_min == 10e9+1&&result_max!=0)
//         cout<<result_max<<' '<<result_max;
//     else if(result_min != 10e9+1&&result_max==0)
//         cout<<result_min<<' '<<result_min;
//     else    
//         cout<<result_min<<' '<<result_max;

//     return 0;
// }


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin>>l>>k;
    for(int i=0;i<l;i++)
    {
        cin>>logs[i];
    }
    LL n0 = 1;
    LL n1 = 10e10;

    while (n0<=n1)
    {
        LL mid=(n0+n1)/2;
        if(justify(mid)<=0)
        {
            n1 = mid-1;
        }
        else
        {
            n0 = mid+1;
        }
    }
    result_min = n0;

    n0 = 1;
    n1 = 10e10;

    while (n0<=n1)
    {
        LL mid=(n0+n1)/2;
        if(justify(mid)<0)
        {
            n1 = mid-1;
        }
        else
        {
            n0 = mid+1;
        }
    }
    result_max = n1;

    if(justify(result_min)==0&&justify(result_max)==0)
        cout<<result_min<<' '<<result_max;
    else if(justify(result_min)!=0&&justify(result_max)==0)
        cout<<result_max<<' '<<result_max;
    else if(justify(result_min)==0&&justify(result_max)!=0)
        cout<<result_min<<' '<<result_min;
    else
        cout<<-1;


    return 0;
}


//第一次:最大最小统一一个二分，WA
//第二次：最小最大分别两次二分，AC