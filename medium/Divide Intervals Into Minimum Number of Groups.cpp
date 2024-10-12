class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        int ans=0;
        map<int,int> m;
        for(auto x:a)
        {
            m[x[0]]++;
            m[x[1]+1]--;
        }
        int s=0;
        for(auto x: m)
        {
            s+=x.second;
            ans=max(ans,s);
        }
        return ans;
    }
};
