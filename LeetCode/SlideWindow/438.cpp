#include <bits/stdc++.h>

using namespace std;



vector<int> findAnagrams(string s, string t) {
    unordered_map<char,unsigned int> need,window;
    vector<int> res;
    if(s.size()<t.size())   return res;
    for(char c:t)
        need[c]++;
    unsigned left=0,valid=0,len=t.size();
    for(unsigned int i=left;i<left+len;i++){
        char c = s[i];
        if(need.count(c)){
            window[c]++;
            if(need[c]==window[c])
                valid++;
        }
    }
    if(valid==need.size()){
        // if(s.substr(left,len)!=t)
            res.push_back(left);
    }
    while(left+len<s.size()){
        char c_left = s[left];
        left++;
        if(need.count(c_left)){
            if(need[c_left]==window[c_left])
                valid--;
            window[c_left]--;
        }

        char c_right = s[left+len-1];
        if(need.count(c_right)){
            window[c_right]++;
            if(need[c_right]==window[c_right])
                valid++;
        }

        if(valid==need.size()){
            // if(s.substr(left,len)!=t)
                res.push_back(left);
        }          
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    string s = "abab";
    string t = "ab";

    vector<int> res = findAnagrams(s, t);
    for(int i:res){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}