class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>m;
        for(auto x:s)m[x]++;
        int ans=0;
        for(auto x:m)
        {
            if(x.second%2)ans++;
        }
        int n=s.size();
        if(ans<=k && k<=n)return 1;
        return 0;
    }
};
