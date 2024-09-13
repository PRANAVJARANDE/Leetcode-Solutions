class Solution {
public:

    int n;
    int helper(string s,int in,unordered_map<string,int>&m)
    {
        if(in>=n)
            return 0;
        
        int ans=10000;
        for(int i=in;i<n;i++)
        {
            string t=s.substr(in,i-in+1);
            if(m.find(t)!=m.end())
            {
                ans=min(ans,1+helper(s,i+1,m));
            }
        }
        return ans;
    }


    int minimumBeautifulSubstrings(string s) 
    {
        n=s.length();
        unordered_map<string,int> m;
        m["1"]++;
        m["101"]++;
        m["11001"]++;
        m["1111101"]++;
        m["1001110001"]++;
        m["110000110101"]++;
        m["11110100001001"]++;

        if(helper(s,0,m)==10000)
        {
            return -1;
        }
        return helper(s,0,m);
    }
};
