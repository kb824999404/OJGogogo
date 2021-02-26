#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 5001;

int ID[MAX];
int Score[MAX];

void qsort(int l,int r)
{
    if(l>=r)    return;
    int middle = Score[(l+r)/2];
    int i=l,j=r;
    while (i<=j)
    {
        while(Score[i]>middle)  i++;
        while(Score[j]<middle)  j--;
        if(i<=j)
        {
            swap(Score[i],Score[j]);
            swap(ID[i],ID[j]);
            i++;
            j--;
        }
        
    }
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}

void sortByID(int l,int r)
{
    for(int i=l+1;i<=r;i++)
        for(int j=r;j>l;j--)
            if(ID[j]<ID[j-1])
            {
                swap(ID[j],ID[j-1]);
                swap(Score[j],Score[j-1]);
            }

}

void sortID(int n)
{
    int curScore = Score[0];
    for(int i=1;i<n;i++)
    {
        if(Score[i]==Score[i-1])
        {
            int low = i-1,high=i;
            curScore = Score[i];
            while (high<n)
            {
                if(Score[high]==curScore)
                    high++;
                else
                    break;
            }            
            sortByID(low,high-1);
            i=high;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>ID[i]>>Score[i];
    }
    qsort(0,n-1);
    sortID(n);
    int scoreLine=Score[(int)floor((float)m*1.5f)-1];
    int result_n = 0;
    for(int i=0;i<n;i++)
    {
        if(Score[i]<scoreLine)
        {
            result_n = i;
            break;
        }
    }
    cout<<scoreLine<<' '<<result_n<<endl;
    for(int i=0;i<result_n;i++)
    {
        cout<<ID[i]<<' '<<Score[i]<<endl;
    }

    return 0;
}