class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
        for(auto x: items1)
        {
            q1.push({x[0],x[1]});
        }
        for(auto x: items2)
        {
            q1.push({x[0],x[1]});
        }


        ans.push_back({q1.top().first,q1.top().second});
        q1.pop();
        while(!q1.empty())
        {
            if(ans.back()[0]==q1.top().first)
            {
                ans.back()[1]+=q1.top().second;
            }
            else
            {
                ans.push_back({q1.top().first,q1.top().second});
            }
            q1.pop();
        }

        return ans;
        
    }
};
