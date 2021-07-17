#include <bits/stdc++.h>
using namespace std;

// int jump(vector<int>& nums) {
//     int Len = nums.size();
//     if(Len==1) return 0;
//     vector<int> ends = vector<int>(Len);
//     for(int i=0;i<Len;i++){
//         ends[i] = i + nums[i];
//     }
//     int index=0,cur_end=0,next_end=0,count=0;
//     while(index<Len&&index<=cur_end){
//         while(index<Len&&index<=cur_end){
//             next_end = max(next_end,ends[index]);
//             index++;
//         }
//         count++;
//         cur_end = next_end;
//         if(cur_end>=Len-1) return count;
//     }
//     return -1;
// }
int jump(vector<int>& nums) {
    int Len = nums.size();
    if(Len==1) return 0;
    int cur_end=0,next_end=0,count=0;
    for(int i=0;i<Len-1;i++){
        next_end = max(next_end , nums[i]+i );
        if(i>=cur_end){
            count++;
            cur_end = next_end;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    auto nums = vector<int>{2,3,1,1,4};
    cout << jump(nums);

    return 0;
}