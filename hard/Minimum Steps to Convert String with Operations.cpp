class Solution {
public:
int calc(string s1,string s2)
    {
        map<pair<char,char>,int>m;
        int n=s1.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i])continue;
            m[{s1[i],s2[i]}]++;
            m[{s2[i],s1[i]}]--;
            if(m[{s2[i],s1[i]}]>=0)ans++;
        }
        // cout<<ans<<" --- "<<endl;
        // for(auto x:m)
        // {
        //     cout<<"{ "<<x.first.first<<" "<<x.first.second<<" }  - "<<x.second<<endl;
        // }
        vector<pair<int,int>>v1;
        for(auto x:m)
        {
            if(x.second>0)ans+=x.second;
        }
        return ans;
    }

    int minOperations(string w1, string w2) 
    {
        int n=w1.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++)dp[i]=i;
        for(int i=0;i<n;i++)
        {
            int res=dp[i];
            for(int j=i+1;j<=n;j++)
            {
                int sz=j-i;
                string s1=w1.substr(i,sz);
                string s2=w2.substr(i,sz);
                int op1=calc(s1,s2);
                reverse(s1.begin(),s1.end());
                int op2=1+calc(s1,s2);
                dp[j]=min(dp[j],dp[i]+min(op1,op2));
            }
        }
        return dp[n];
    }
};
