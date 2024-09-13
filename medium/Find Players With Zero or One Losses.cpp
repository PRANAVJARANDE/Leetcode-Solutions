class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) 
    {
        map<int,int>los,win;
        for(auto x: mat)
        {
            win[x[0]]++;
            los[x[1]]++;
        }

        vector<int> a1,a2;
        for(auto x: los)
        {
            if(x.second==1) a2.push_back(x.first);
        }

        for(auto x: win)
        {
            if(los[x.first]==0)
            {
                a1.push_back(x.first);
            }
        }
        return {a1,a2};
    }
};
