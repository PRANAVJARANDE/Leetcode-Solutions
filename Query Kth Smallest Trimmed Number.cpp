class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& que) 
    {
        vector<int>ans;
        int ss=nums[0].size();
        for(auto x: que)
        {
            int tr=x[1];
            int k=x[0];

            priority_queue<pair<string,int>> q1;
            for(int i=0;i<nums.size();i++)
            {
                q1.push({nums[i].substr(ss-tr),i});
                if(q1.size()>k)
                {
                    q1.pop();
                }
            }
            ans.push_back(q1.top().second);
        }
        return ans;
    }
};
