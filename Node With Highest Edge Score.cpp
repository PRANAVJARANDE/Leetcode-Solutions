class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        unordered_map<int,long> m;
        int ans;
        long count=INT_MIN;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i]]+=i;
            if(count<m[edges[i]])
            {
                ans=edges[i];
                count=m[edges[i]];
            }
            else if(count==m[edges[i]])
            {
                ans=min(ans,edges[i]);
            }
        }
        return ans;
    }
};
