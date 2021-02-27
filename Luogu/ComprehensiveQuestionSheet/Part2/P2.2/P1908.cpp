#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 500001;
int A[MAX];
int B[MAX];
long long int Count=0;



void merge(int* A,int ll,int lr,int rl,int rr)
{

    int i =ll,j=rl;
    int p=0;
    while (i<=lr&&j<=rr)
    {
        if(A[i]<=A[j])
            B[p++] = A[i++];
        else
        {
            B[p++] = A[j++];
            Count+=lr-i+1;
        }
    }
    while (i<=lr)
        B[p++] = A[i++];    
    while (j<=rr)
        B[p++] = A[j++];
    for(int k=0;k<=rr-ll;k++)
        A[ll+k] = B[k];
    
}

void mergeSort(int* A,int l,int r)
{
    if(r>l)
    {
        int mid = (l+r)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,r);
        merge(A,l,mid,mid+1,r);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    Count=0;
    mergeSort(A,0,n-1);
    printf("%lld",Count);

    return 0;
}

//IN：
// 6 5 4 2 6 3 1
// OUT: 11
// 1 2 3 4 5 6
// 第一种：归并排序