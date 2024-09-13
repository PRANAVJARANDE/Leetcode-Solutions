class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        priority_queue<int> q1;
        set<int> s1;
        for(int i=0;i<nums.size();i++)
        {
            s1.insert(nums[i]);
        }
        for(int x:s1)
        {
            q1.push(x);
        }

        if(q1.size()<3)
        {
            return q1.top();
        }
        int h=1;
        while(h<3)
        {
            q1.pop();
            h++;
        }
        return q1.top();
    }
};
