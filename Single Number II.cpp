class Solution {
public:

    bool getbit(int n,int p)
    {
        return n & 1<<p;
    }
    int setbit(int n,int p)
    {
        int y=n | 1<<p;
        return y;
    }

    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        int k=1;
        for(int i=0;i<32;i++)
        {
            int k=0;
            for(int j=0;j<nums.size();j++)
            {
                if(getbit(nums[j],i))
                {
                    k++;
                }
            }
            k=k%3;
            if(k==1)
            {
                ans=setbit(ans,i);
            }  
        }
        return ans;
    }
};
