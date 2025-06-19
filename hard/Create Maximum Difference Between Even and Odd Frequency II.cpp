class Solution {
public:
    int helper(char a, char b, string s, int k) 
    {
        int n=s.size();
        vector<vector<int>>ps(n+1,vector<int>(2, 0));
        for(int i=1;i<=n;i++) 
        {
            if(s[i-1]==a)ps[i][0]++;
            if(s[i-1]==b)ps[i][1]++;
            ps[i][0]+=ps[i-1][0];
            ps[i][1]+=ps[i-1][1];
        }
        vector<vector<int>>pv(2,vector<int>(2,INT_MIN));
        int ans=INT_MIN;
        int l=0;
        for (int i = k; i <= n; i++) 
        {
            while(i-l>=k && ps[i][0]>ps[l][0] && ps[i][1]>ps[l][1]) 
            {
                int pa=ps[l][0]%2;
                int pb=ps[l][1]%2;
                pv[pa][pb]=max(pv[pa][pb],ps[l][1]-ps[l][0]);
                l++;
            }

            int p1=ps[i][0]%2;
            int p2=ps[i][1]%2;
            int tsub=pv[1-p1][p2];  
            if(tsub!=INT_MIN)
            {
                int res=ps[i][0]-ps[i][1]+tsub;
                ans=max(ans,res);
            }
        }
        return ans;
    }


    int maxDifference(string s, int k) 
    {
        int n=s.size();
        int ans=INT_MIN;
        for(char a='0';a<='4';a++) 
        {
            for(char b='0';b<='4';b++) 
            {
                if(a!=b)
                {
                    int res=helper(a,b,s,k);
                    ans=max(ans,res);
                }
            }
        }
        if(ans==INT_MIN)ans=-1;
        return ans;
    }
};
