#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    int Len = points.size();
    if(Len<=1) return Len;
    sort(points.begin(),points.end(),
        [](vector<int>&x,vector<int>&y){
            if(x[0]<y[0]) return true;
            else if(x[0]>y[0]) return false;
            else return x[1]<y[1];
    });
    int left=points[0][0],right=points[0][1];
    int count=1;
    for(int i=1;i<Len;i++){
        vector<int>& P=points[i];
        if(P[0]>right){
            left = P[0];
            right = P[1];
            count++;
        }
        else{
            left = max(left,P[0]);
            right = min(right,P[1]);            
        }

    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto points = vector<vector<int>>{{1,2},{2,3},{3,4},{4,5}};
    cout << findMinArrowShots(points);

    return 0;
}