#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size()==1){
        if(target==nums[0])
            return vector<int>{0,0};
        else
            return vector<int>{-1,-1};
    }
    int left = 0;
    int right = nums.size()-1;
    bool hasTarget = false;
    vector<int> res=vector<int>(2);
    while(left<=right){
        int mid = (left+right)/2;
        if(target == nums[mid]){
            right = mid-1;
            hasTarget = true;
        }
        else if(target<nums[mid]){
            right = mid - 1;
        }
        else if(target>nums[mid]){
            left = mid + 1;
        }
    }
    if(left<0)  left = 0;
    res[0] = left;
    left = 0;
    right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(target == nums[mid]){
            left = mid+1;
            hasTarget = true;
        }
        else if(target<nums[mid]){
            right = mid - 1;
        }
        else if(target>nums[mid]){
            left = mid + 1;
        }
    }
    if(right>=nums.size())  right = nums.size()-1;
    res[1] = right;
    if(hasTarget)
        return res;
    else
        return vector<int>{-1,-1};
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{2,2};
    vector<int> res = searchRange(nums,2);
    cout << "[" << res[0] << "," << res[1] << "]\n";

    return 0;
}