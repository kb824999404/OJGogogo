#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    vector<pair<int,int>> list;
    for(unsigned i=0;i<nums.size();i++){
        list.push_back( pair<int,int>{ i,nums[i] } );
    } 
    sort(list.begin(),list.end(),[](pair<int,int>& x,pair<int,int>& y ){
        return x.second<y.second;
    });
    int Len=nums.size();
    int p1=0,p2=Len-1;
    while(p1<Len&&p2>=0&&p1<p2){
        int n1 = list[p1].second;
        int n2 = list[p2].second;
        int sum = n1+n2;
        if(sum==target){
            return vector<int>{list[p1].first,list[p2].first};
        }
        else if(sum<target){
            p1++;
        }
        else{
            p2--;
        }
    }

    return vector<int>{0,0};
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> nums{ 3,2,4 };

    auto result = twoSum(nums,6);
    cout << result[0] << " " << result[1];


    return 0;
}