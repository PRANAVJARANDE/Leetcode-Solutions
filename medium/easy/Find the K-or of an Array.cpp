class Solution {
public:
    int findKOr(vector<int>& nums, int k) 
    {
            int ans=0;
            for(int i=0;i<32;i++)
            {
                    int z=0;
                for(int x: nums)
                {
                        if(x & (1<<i))
                        {
                                z++;
                        }
                        if(z==k)
                        {
                                break;
                        }
                }
                    if(z==k)
                    {
                        ans=ans | (1<<i);
                    }
            }
        return ans;
    }
};
