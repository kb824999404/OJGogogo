#include <bits/stdc++.h>
using namespace std;

int videoStitching(vector<vector<int>>& clips, int time) {
    int Len = clips.size();
    if(Len==1) return 1;

    sort(clips.begin(),clips.end(),
        [](vector<int>& x,vector<int>& y){
            if(x[0]<y[0]) return true;
            else if(x[0]>y[0]) return false;
            else return x[1]>y[1];
    });
    int end=clips[0][1],next_end=0;
    int count = 1;
    int index = 1;
    while(index<Len&&clips[index][0]<=end){
        //选起点最大的重叠区间
        while(index<Len&&clips[index][0]<=end){
            next_end = max(next_end,clips[index][1]);
            index++;
        }
        count++;
        end = next_end;
        if(end>=time){
            return count;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto clips = vector<vector<int>>{{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};
    // auto clips = vector<vector<int>>{{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    cout << videoStitching(clips,9);

    return 0;
}