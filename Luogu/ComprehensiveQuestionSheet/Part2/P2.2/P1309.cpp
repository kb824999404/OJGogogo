#include <iostream>
#include <algorithm>

using namespace std;
const int MAX=200100;

long long int Score[MAX];
long long int Weight[MAX];
int Rank[MAX];
int tempRank[MAX];
int Win[MAX];
int Lose[MAX];


bool cmp(int x,int y)  
{  
  if(Score[x-1]==Score[y-1])   return x<y;
  return Score[x-1]>Score[y-1];
}  

void merge(int N)
{
    int i=0,j=0,p=0;
    while(i<N&&j<N)
    {
        if(cmp(Win[i],Lose[j]))
            tempRank[p++] = Lose[j++];
        else
            tempRank[p++] = Win[i++];
    }
    while(i<N)
        tempRank[p++] = Win[i++];
    while(j<N)
        tempRank[p++] = Win[j++];
    
    for(int i=0;i<2*N;i++)
        Rank[i] = tempRank[i];
}

void round(int N)
{
    for(int i=0;i<N;i++)
    {
        if(Weight[Rank[2*i]-1]>=Weight[Rank[2*i+1]-1])
        {
            Score[Rank[2*i]-1]++;
            Win[i] = Rank[2*i];
            Lose[i] = Rank[2*i+1];
        }
        else
        {
            Score[Rank[2*i+1]-1]++;
            Win[i] = Rank[2*i+1];
            Lose[i] = Rank[2*i];
        }
    }
    merge(N);
}

void printScore(int n)
{
    cout<<"Score:\t";
    for(int i=0;i<n;i++)
    {
        cout<<Score[i]<<' ';
    }
    cout<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int N,R,Q;
    cin>>N>>R>>Q;   
    for(int i=0;i<2*N;i++)
        cin>>Score[i];
    for(int i=0;i<2*N;i++)
        cin>>Weight[i];
    for(int i=0;i<2*N;i++)
        Rank[i] = i+1;
    sort(Rank,Rank+2*N,cmp);
    // printScore(2*N);

    for(int i=0;i<R;i++)
    {
        round(N);
        // printScore(2*N);
    }
    sort(Rank,Rank+2*N,cmp);
    cout<<Rank[Q-1];

    return 0;
}

//第一次：每次都全部排序，TLE
//第二次：每次只归并，WA