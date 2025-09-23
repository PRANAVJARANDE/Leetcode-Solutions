class Solution {
    public:

    vector<int> help(string&s)
    {
        int n=s.size();
        int num=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                ans.push_back(num);
                num=0;
            }
            else 
            {
                num=num*10+(s[i]-'0');
            }
        }
        ans.push_back(num);
        return ans;
    }

    int compareVersion(string version1, string version2) 
    {
        vector<int>v1=help(version1);
        vector<int>v2=help(version2);
        int n=v1.size(),m=v2.size();
        for(int i=0;i<min(n,m);i++)
        {
            if(v1[i]>v2[i])return 1;
            else if(v1[i]<v2[i])return -1;
        }
        for(int i=min(n,m);i<n;i++)
        {
            if(v1[i]>0)return 1;
        }
        for(int i=min(n,m);i<m;i++)
        {
            if(v2[i]>0)return -1;
        }
        return 0;
    }
};
