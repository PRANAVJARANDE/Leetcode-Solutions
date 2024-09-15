class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        string vov="aeiou";
        vector<vector<int>> v1(n,vector<int>(5,0));
        map<vector<int>,int>m;
        m[v1[0]]=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(s[i]==vov[j])v1[i][j]++;
                if(i-1>=0)v1[i][j]+=v1[i-1][j];
                v1[i][j]%=2;
            }
            if(m.find(v1[i])==m.end())
            {
                m[v1[i]]=i;
            }
            else
            {
                ans=max(ans,i-m[v1[i]]);
            }
        }
        return ans;
    }
};
