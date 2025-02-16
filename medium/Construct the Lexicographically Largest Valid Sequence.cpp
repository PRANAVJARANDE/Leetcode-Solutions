class Solution {
public:

    int n;
    int sz;
    bool helper(int in,vector<int>&res,vector<int>&vis)
    {
        if(in>=sz)return 1;
        if(res[in]!=-1)return helper(in+1,res,vis);

        for(int i=n;i>=1;i--)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                res[in]=i;
                if(i==1)
                {
                    bool b=helper(in+1,res,vis);
                    if(b==1)return 1;
                }
                else if(in+i<sz && res[i+in]==-1)
                {
                    res[in+i]=i;
                    bool b=helper(in+1,res,vis);
                    if(b==1)return 1;
                    res[in+i]=-1;
                }
                res[in]=-1;
                vis[i]=0;
            }
        }
        return 0;
    }

    vector<int> constructDistancedSequence(int nn) 
    {
        n=nn;
        sz=2*n-1;
        vector<int>res(sz,-1);
        vector<int>vis(n+1,0);
        helper(0,res,vis);
        return res;
    }
};
