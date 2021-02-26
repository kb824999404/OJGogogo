#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=101;

int in_array[MAX];
int out_array[MAX];

int quick(int *A,int low,int high)
{
    int tmp = A[low];
    int left=low,right=high;
    while (true)
    {
        while (A[right]>=tmp&&left<right)
            right--;
        while (A[left]<=tmp&&left<right)
            left++;  
        if(left>=right) break;
        int x=A[left];
        A[left]=A[right];
        A[right]=x;
    }
    A[low]=A[right];
    A[right]=tmp;
    return right;
}

void quicksort(int *A,int low,int high)
{
    if(low<high)
    {
        int middle = quick(A,low,high);
        quicksort(A,low,middle-1);
        quicksort(A,middle+1,high);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    cin >>n;

    for(int i=0;i<n;i++)
    {
        cin>>in_array[i];
    }

    // sort(in_array,in_array+n);
    quicksort(in_array,0,n-1);


    out_array[0] = in_array[0];
    int out_n=1,cur_x=out_array[0];

    for(int i=1;i<n;i++)
    {
        if(in_array[i]>cur_x)
        {
            out_array[out_n++]=in_array[i];
            cur_x = in_array[i];
        }
    }
    cout<<out_n<<endl;
    for(int i=0;i<out_n;i++)
    {
        if(i>0) cout<<' ';
        cout<<out_array[i];
    }
    cout<<endl;

    return 0;
}


// 第一种：调用sort
// 第二种：用自己的quicksort