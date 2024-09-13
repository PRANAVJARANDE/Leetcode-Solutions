class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        priority_queue<pair<long long,int>> q1;
        for(auto x: dimensions)
        {
            int dia=x[0]*x[0] + x[1]*x[1];
            int area=x[0]*x[1];
            q1.push({dia,area});
        }
        int dia=q1.top().first;
        int ans=q1.top().second;
        
        while(!q1.empty() && q1.top().first==dia)
        {
            ans=max(ans,q1.top().second);
            q1.pop();
        }
        return ans;
        
    }
};
