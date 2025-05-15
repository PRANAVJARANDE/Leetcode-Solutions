class Solution {
public:

    int findHam(string a,string b)
    {
        int ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])ans++;
        }
        return ans;
    }


    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) 
    {
        vector<string>ans;

        int n=w.size();
        vector<int>dp(n,0);
        vector<int>nx(n,n);
        for(int i=n-1;i>=0;i--)
        {
            int res=1;
            int nex=n;
            for(int j=i+1;j<n;j++)
            {
                if(g[i]!=g[j] && w[i].size()==w[j].size() && findHam(w[i],w[j])==1)
                {
                    if(1+dp[j]>res)
                    {
                        res=1+dp[j];
                        nex=j;
                    }
                }
            }
            dp[i]=res;
            nx[i]=nex;
        }
        int res=0;
        for(auto x:dp)
        {
            res=max(res,x);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==res)
            {
                int in=i;
                while(in<n)
                {
                    ans.push_back(w[in]);
                    in=nx[in];
                }
                return ans;
            }
        }
        return ans;
    }
};
