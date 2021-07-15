#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(nums[mid]==target)   return mid;
        else if(target < nums[mid]) right = mid - 1;
        else if(target > nums[mid]) left = mid + 1;
    }

    return -1;

}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{-1,0,3,5,9,12};
    cout << search(nums,9) << endl;

    return 0;

}