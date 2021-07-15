#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,unsigned int>window;
    unsigned left=0,right=0,repeat=0;
    unsigned start=0,len=0;
    while(right<s.size()){
        char c_right = s[right];
        window[c_right]++;
        if(window[c_right]>1)
            repeat++;
        right++;
        while(repeat>0&&left<right){
            char c_left = s[left];
            left++;
            if(window[c_left]==2)
                repeat--;
            window[c_left]--;
        }
        len = max(len,right-left);
    }
    return len;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    string s = "bbbbbb";

    cout << lengthOfLongestSubstring(s);

    return 0;
}