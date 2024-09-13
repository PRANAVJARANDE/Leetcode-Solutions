class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n=ed.size();
        vector<int>indeg(n+2,0);
        for(auto x:ed)
        {
            indeg[x[0]]++;
            indeg[x[1]]++;
            if(indeg[x[0]]>1)return x[0];
            if(indeg[x[1]]>1)return x[1];
        }
        return 0;
    }
};
