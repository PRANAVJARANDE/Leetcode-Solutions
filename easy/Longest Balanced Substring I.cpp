class Solution {
public:

    bool check(vector<int>&m)
    {
        int pv=-1;
        for(auto x:m)
        {
            if(x==0)continue;
            if(pv==-1)pv=x;
            if(pv!=x)return 0;
        }
        return 1;
    }
    
    int longestBalanced(string s) 
    {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>m(26,0);
            for(int j=i;j<n;j++)
            {
                m[s[j]-'a']++;
                if(check(m))ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
