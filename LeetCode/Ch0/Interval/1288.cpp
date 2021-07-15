#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
    vector<vector<int>>& secondList)  {

    vector<vector<int>> result;
    if(firstList.empty()||secondList.empty())   return result;
    vector<vector<int>> bigList;
    bigList.resize(firstList.size()+secondList.size());
    merge(firstList.begin(),firstList.end(),secondList.begin(),secondList.end(),
        bigList.begin());


    int left = bigList[0][0],right=bigList[0][1];
    for(unsigned i=1;i<bigList.size();i++){
        vector<int>& interval = bigList[i];
        if(interval[0]>right){
            left = interval[0];
            right = interval[1];
        }
        else if(interval[1]<=right){
            result.push_back(interval);
        }
        else{
            result.push_back(vector<int>{ interval[0] , right });
            left = interval[0];
            right = interval[1];
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<vector<int>> firstList{ {0,2},{5,10},{13,23},{24,25} };
    vector<vector<int>> secondList{ {1,5},{8,12},{15,24},{25,26} };
    auto intervals = intervalIntersection(firstList,secondList);
    for(auto i:intervals){
        cout << i[0] << "," << i[1] << endl;
    }


    return 0;
}
