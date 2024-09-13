class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int,map<int,int>> m;
        for(auto x: pick)
        {
            m[x[0]][x[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int maxi=0;
            for(auto y:m[i])
            {
                maxi=max(maxi,y.second);
            }
            if(maxi>i)
            {
                ans++;
            }
        }
        return ans;
        
    }
};
