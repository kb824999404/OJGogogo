#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(intervals.begin(),intervals.end(),[](vector<int>& i1,vector<int>& i2){
        if(i1[0]<i2[0]) return true;
        else if(i1[0]==i2[0]) return i1[1]>i2[1];
        else return false;
    });

    // for(vector<int>& interval:intervals){
    //     cout << interval[0] << ' ' << interval[1] << endl;
    // }

    vector<vector<int>> result;
    int left = intervals[0][0],right=intervals[0][1];
    for(unsigned i=1;i<intervals.size();i++){
        vector<int>& interval = intervals[i];
        if(interval[0]>right){
            result.push_back(vector<int>{left,right});
            left = interval[0];
            right = interval[1];
        }
        else{
            right = max( right , interval[1]);
        }
    }
    result.push_back(vector<int>{left,right});

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<vector<int>> intervals{ {1,4},{2,3} };

    auto interval = merge(intervals);
    for(auto i:interval){
        cout << i[0] << "," << i[1] << endl;
    }


    return 0;
}
