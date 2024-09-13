class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
            vector<int> ans(n,0);
            for(auto x: edges)
            {   
                ans[x[1]]++;
            }
            
            vector<int> h;
            for(int i=0;i<n;i++)
            {
                if(ans[i]==0)h.push_back(i);
            }
            
            if(h.size()==1)
            {
                return h[0];
            }
            return -1;
    }
};
