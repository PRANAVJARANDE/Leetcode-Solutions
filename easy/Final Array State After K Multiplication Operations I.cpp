class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        for(int i=0;i<n;i++)
        {
            q1.push({nums[i],i});
        }
        while(k--)
        {
            int in=q1.top().second;
            q1.pop();
            nums[in]*=m;
            q1.push({nums[in],in});
        }
        return nums;
    }
};
