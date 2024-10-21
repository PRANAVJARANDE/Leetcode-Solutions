class Solution {
public:

    int n;
    int helper(int in,string s,map<string,int>m)
    {
        if(in>=n)return 0;
        int ans=0;
        for(int j=in;j<n;j++)
        {
            string res=s.substr(in,j-in+1);
            if(m.find(res)==m.end())
            {
                m[res]++;
                ans=max(ans,1+helper(j+1,s,m));
                m.erase(res);
            }
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        n=s.size();
        map<string,int> m;
        int ans=helper(0,s,m);
        return ans;
    }
};
