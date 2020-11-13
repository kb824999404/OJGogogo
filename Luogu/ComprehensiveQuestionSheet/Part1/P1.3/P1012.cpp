#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string& str1,string& str2)
{
    int len1=str1.size();
    int len2=str2.size();
    for(int i=0;i<len1&&i<len2;i++)
    {
        char a=str1.at(i);
        char b=str2.at(i);
        if(a<b) return true;
        else if(a>b) return false;
        else
        {
            if(i==len1-1&&len1<len2)
            {
                if(str1.at(0)<=str2.at(i+1))  return true;
                else return false;
            }
            if(i==len2-1&&len2<len1)
            {
                if(str2.at(0)>str1.at(i+1))  return true;
                else return false;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    string strs[20];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    std::sort(strs,strs+n,cmp);
    for(int i=n-1;i>=0;i--)
    {
        cout<<strs[i];
    }

    return 0;
}