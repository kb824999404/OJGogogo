#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int>& nums, int target,int start) {
    vector<vector<int>> result;

    int Len=nums.size();
    int p1=start,p2=Len-1;
    while(p1<Len&&p2>=start&&p1<p2){
        int n1 = nums[p1];
        int n2 = nums[p2];
        int sum = n1+n2;
        if(sum==target){
            result.push_back(vector<int>{n1,n2});
            while(p1<p2 && nums[p1]==n1)
                p1++;
            while(p1<p2 && nums[p2]==n2)
                p2--;
        }
        else if(sum<target){
            while(p1<p2 && nums[p1]==n1)
                p1++;
        }
        else{
            while(p1<p2 && nums[p2]==n2)
                p2--;
        }
    }

    return result;
}
vector<vector<int>> threeSum(vector<int>& nums, int target,int start) {
    vector<vector<int>> result;
    if(nums.size()<3)   return result;
    for(unsigned int i=start;i<nums.size()-2;i++){
        int n = nums[i];
        vector<vector<int>> results_two = twoSum(nums,target-n,i+1);
        for(vector<int> item:results_two){
            item.push_back(n);
            result.push_back(item);
        }
        while(i<nums.size()-2&&nums[i]==nums[i+1]) i++;
    }
    return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if(nums.size()<4)   return result;
    sort(nums.begin(),nums.end());
    for(unsigned int i=0;i<nums.size()-3;i++){
        int n = nums[i];
        vector<vector<int>> results_three = threeSum(nums,target-n,i+1);
        for(vector<int> item:results_three){
            item.push_back(n);
            result.push_back(item);
        }
        while(i<nums.size()-3&&nums[i]==nums[i+1]) i++;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{1,0,-1,0,-2,2};

    auto result = fourSum(nums,0);
    for(auto item:result)
        cout << item[0] << " " << item[1]<<" " << item[2] <<" " << item[3] <<endl;


    return 0;
}