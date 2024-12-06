class Solution {
public:
    int maxCount(vector<int>& banned, int n, int ms) {
        set<int> s1;
        for(int x:banned)s1.insert(x);
        int ans=0;
        int in=1;
        while(ms>=in && in<=n)
        {
            if(s1.find(in)!=s1.end())
            {
                in++;
                continue;
            }
            ms-=in;
            in++;
            ans++;
        }
        return ans;
    }
};
