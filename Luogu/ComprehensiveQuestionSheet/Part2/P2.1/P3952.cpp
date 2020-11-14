#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getInputO(string& str)
{
    if(str.at(2)=='1')
        return 0;
    else return atoi(str.substr(4,str.size()-5).c_str());
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t,l,input_o,real_o,depth;
    bool error,right;
    string vars;
    string str_o;
    vector<int> o_stack;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        error=false;
        vars="";
        o_stack.clear();
        scanf("%d ",&l);
        scanf("%s\n",str_o);
        input_o=getInputO(str_o);
        real_o=0;
        depth=0;
        char flag,var;
        int curr_o;
        char start[10],end[10];
        for(int j=0;j<l;j++)
        {
            flag=getchar();

            if(flag=='F')
            {
                depth++;
                scanf(" %c %s %s",&var,start,end);
                if(vars.size()>0)
                {
                    if(vars.find(var)!=vars.npos)
                        error=true;   
                }
                {   
                    if(start[0]=='n')   curr_o=0;
                    else
                    {
                        int start_i=atoi(start),end_i;
                        if(end[0]=='n')
                            curr_o=1;
                        else
                        {
                            end_i=atoi(end);
                            curr_o=(start_i>end_i)?0:1;
                        }
                        
                    }
                    if(o_stack.at(depth-1)<curr_o)  o_stack.at(depth-1)=curr_o;  
                }
                vars.push_back(var);
            }
            else
            {
                if(depth<0)
                {
                    error=true;
                }
                else
                {
                    depth--;
                }
            }
            getchar();
                    
        }
        if(depth>0) error=true;
        if(error)
            printf("ERR");
        else
        {
            for(int k=0;k<o_stack.size();k++)
            {
                real_o+=o_stack.at(k);
            }
            right=(input_o==real_o);
            printf("%s",(right?"Yes":"No"));
        }
        if(i!=t-1)
            putchar('\n');
    }

    return 0;
}