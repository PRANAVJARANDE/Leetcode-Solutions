class Solution {
public:

    int n;
    bool helper(int in,string s,string&res,vector<int>&vis)
    {
        if(in>=n)return 1;
        if(in==-1)
        {
            for(char c='1';c<='9';c++)
            {
                if(vis[c-'0']==0)
                {
                    vis[c-'0']=1;
                    string pv=res;
                    res+=c;
                    if(helper(in+1,s,res,vis))return 1;
                    res=pv;
                    vis[c-'0']=0;
                }
            }
            return 0;
        }

        if(s[in]=='I')
        {
            for(char c=res[in]+1;c<='9';c++)
            {
                if(vis[c-'0']==0)
                {
                    vis[c-'0']=1;
                    string pv=res;
                    res+=c;
                    if(helper(in+1,s,res,vis))return 1;
                    res=pv;
                    vis[c-'0']=0;
                }
            }
        }
        else
        {
            for(char c='1';c<=res[in]-1;c++)
            {
                if(vis[c-'0']==0)
                {
                    vis[c-'0']=1;
                    string pv=res;
                    res+=c;
                    if(helper(in+1,s,res,vis))return 1;
                    res=pv;
                    vis[c-'0']=0;
                }
            }
        }
        return 0;
    }

    string smallestNumber(string s) 
    {
        n=s.size();
        string res="";
        vector<int>vis(11,0);
        helper(-1,s,res,vis);
        return res;
    }
};
