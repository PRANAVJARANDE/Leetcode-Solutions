class Solution {
public:

    bool match(map<char,int>&m1,map<char,int>&m2)
    {
        for(auto x: m2)
        {
            if(m1[x.first]<x.second)return 0;
        }
        return 1;
    }


    long long validSubstringCount(string s, string w2) {
        map<char,int> m2,m1;
        for(auto x:w2)m2[x]++;
        int n=s.size();
        int l=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            m1[s[i]]++;
            while(match(m1,m2))
            {
                ans+=n-i;
                m1[s[l]]--;
                l++;
            }
        }
        return ans;

    }
};
