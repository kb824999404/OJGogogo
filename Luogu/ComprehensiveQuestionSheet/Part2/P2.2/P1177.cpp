#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001

int n;
int A[MAX];

void insertSort(int a[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
        for (int j = i; j > 0 && a[j] < a[j-1]; j--)
            swap(a[j], a[j-1]);
}

void QuickSort(int x,int y){
    if(x<y){
        if (y - x + 1 < 10)
        {
            insertSort(A, x, y);
            return;
        }

        int pivot = (x+y)/2;
        swap(A[x], A[pivot]);

        int tmp=A[x];
        int left=x,right=y;
        while(true){
            while(A[right]>=tmp&&left<right)
                right--;
            while(A[left]<=tmp&&left<right)
                left++;
            if(left>=right)
                break;
            swap(A[left],A[right]);
        }
        A[x] = A[right];
        A[right]=tmp;

        QuickSort(x,right-1);
        QuickSort(right+1,y);
    }

}

void qsort_two(int x,int y)
{
    if(x>=y) return;
    int mid = A[(x+y)/2];
    int i=x,j=y;
    while (i<=j)
    {
        while (A[i]<mid)    i++;
        while (A[j]>mid)    j--;
        if(i<=j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    if(x<j) qsort_two(x,j);
    if(i<y) qsort_two(i,y);
    
}

void qsort(int l,int r)
{
    int mid=A[(l+r)/2];//中间数
    int i=l,j=r;
    do{
        while(A[i]<mid) i++;//查找左半部分比中间数大的数
        while(A[j]>mid) j--;//查找右半部分比中间数小的数
        if(i<=j)//如果有一组不满足排序条件（左小右大）的数
        {
            swap(A[i],A[j]);//交换
            i++;
            j--;
        }
    }while(i<=j);//这里注意要有=
    if(l<j) qsort(l,j);//递归搜索左半部分
    if(i<r) qsort(i,r);//递归搜索右半部分
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    // QuickSort(0,n-1);
    // qsort(0,n-1);
    qsort_two(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<' ';
    }

    return 0;
}


//第一次：自己的quicksort，三个TLE，数组接近有序退化
//第二次：用题解的qsort，AC
//第三次：改进quicksort，随机选取枢轴元素，一个TLE
//第四次：再次改进quicksort，小区间插入排序，一个TLE