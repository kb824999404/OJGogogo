#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int Len = nums.size();
    vector<int> ends = vector<int>(Len);
    for(int i=0;i<Len;i++){
        ends[i] = i + nums[i];
    }
    int index=0,cur_end=0,next_end=0;
    while(index<Len&&index<=cur_end){
        while(index<Len&&index<=cur_end){
            next_end = max(next_end,ends[index]);
            index++;
        }
        cur_end = next_end;
        if(cur_end>=Len-1) return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto nums = vector<int>{3,2,1,0,4};
    cout << canJump(nums);

    return 0;
}