#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PI;
typedef long long LL;
const int MAX=1001;
PI person[MAX];
int n,a,b;

bool cmp(const PI& A,const PI& B){
    return A.first*A.second<B.first*B.second;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin>>n;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        cin>>person[i].first>>person[i].second;
    }
    sort(person,person+n,cmp);
    LL v_max=0;
    LL cur_mul=a;
    for(int i=0;i<n;i++){
        LL v_cur = cur_mul/person[i].second;
        if(v_cur>v_max) v_max=v_cur;
        cur_mul*=person[i].first;
    }
    cout<<v_max;

    return 0;
}

//第一次：按右手递增排序
//第二次：按乘积递增排序
//第三次：高精度TODO
//题解：https://www.luogu.com.cn/problem/solution/P1080