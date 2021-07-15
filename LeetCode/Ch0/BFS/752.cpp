#include <bits/stdc++.h>

using namespace std;

char getNewPlus(char cur){
    if(cur=='9')
        return '0';
    else
        return cur+1;
}
char getNewMinus(char cur){
    if(cur=='0')
        return '9';
    else
        return cur-1;
}

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited;
    unordered_set<string> set_deadends(deadends.begin(),deadends.end());
    if(set_deadends.count("0000"))  return 0;
    int step = 1;
    deque<string> Q;
    Q.push_back("0000");
    while(!Q.empty()){
        int count = Q.size();
        for(int j=0;j<count;j++){
            string cur = Q.back();
            Q.pop_back();
            visited.insert(cur);
            for(int i=0;i<4;i++){
                {
                    string str_new = cur;
                    str_new[i] = getNewPlus(str_new[i]);
                    if(!set_deadends.count(str_new)
                        &&!visited.count(str_new)){
                        if(str_new==target) return step;
                        Q.push_front(str_new);
                    }
                }
                {
                    string str_new = cur;
                    str_new[i] = getNewMinus(str_new[i]);
                    if(!set_deadends.count(str_new)
                        &&!visited.count(str_new)){
                        if(str_new==target) return step;
                        Q.push_front(str_new);
                    }
                }

            }
        }
        step++;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    // vector<string> deadends{ "0201","0101","0102","1212","2002" };
    // string target = "0202";
    vector<string> deadends{ "8887","8889","8878","8898","8788","8988","7888","9888" };
    string target = "8888";
    cout << openLock(deadends,target);

    return 0;
}
