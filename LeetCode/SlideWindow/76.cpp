#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,unsigned int> need,window;
    for(char c:t)
        need[c]++;
    unsigned left=0,right=0,valid=0;
    unsigned start=0,len=INT_MAX;
    while(right<s.size()){
        char c_right = s[right];
        if(need.count(c_right)){
            window[c_right]++;
            if(need[c_right]==window[c_right])
                valid++;
        }
        right++;
        while(valid==need.size()){
            if((right-left)<len){
                start = left;
                len = right-left;
            }
            char c_left = s[left];
            left++;
            if(need.count(c_left)){
                if(need[c_left]==window[c_left])
                    valid--;
                window[c_left]--;
            }
        }
    }
    if(len==INT_MAX)    return "";
    else return s.substr(start,len);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s,t);

    return 0;
}