class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int s=0;
        map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            s=s%k;
            if(m.find(s)!=m.end())
            {
                if(i-m[s]>1)return 1;
            }
            else
            {
                m[s]=i;
            }
        }
        return 0;
    }
};
