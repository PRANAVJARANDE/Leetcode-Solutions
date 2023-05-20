class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set<int> s1;
        for(int i=0;i<nums.size();i++)
        {
            s1.insert(nums[i]);
        }
        priority_queue<int,vector<int> ,greater<int>> q1;
        for(int x : s1)
        {
            q1.push(x);
        }

        int ans=1;
        while(!q1.empty())
        {
            if(q1.top()<=0)
            {
                q1.pop();
                continue;
            }
            if(q1.top()>ans)
            {
                return ans;
            }
            ans++;
            q1.pop();
        }
        return ans;
        

        
    }
};
