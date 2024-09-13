class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> pos,neg;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {   
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        int i1=0,i2=0;
        for(int i=0;i<n;i+=2)
        {
            nums[i]=pos[i1++];
            nums[i+1]=neg[i2++];
        }
        return nums;
    }
};
