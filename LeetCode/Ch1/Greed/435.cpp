#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int Len = intervals.size();
    if(Len<=1) return 0;
    sort(intervals.begin(),intervals.end(),
        [](vector<int>&x,vector<int>&y){
            if(x[0]<y[0]) return true;
            else if(x[0]>y[0]) return false;
            else return x[1]<y[1];
    });
    int right=intervals[0][1];
    int count=0;
    for(int i=1;i<Len;i++){
        vector<int>& I=intervals[i];
        if(I[0]>=right){
            right = I[1];
        }
        else{
            count++;
            if(I[1]<=right){
                right = I[1];
            }
        }

    }
    return count;

}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto intervals = vector<vector<int>>{{1,2}, {2,3}, {1,2}};
    cout << eraseOverlapIntervals(intervals);

    return 0;
}