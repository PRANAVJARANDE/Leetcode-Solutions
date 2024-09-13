class Solution {
public:

    bool getbit(int n,int p)
    {
        return n & 1<<p;
    }

    vector<int> singleNumber(vector<int>& nums) 
    {
        int xorsum=0;
        for(int i=0;i<nums.size();i++)
        {
            xorsum=xorsum^nums[i];
        }

        int p=0;
        while(!getbit(xorsum,p))
        {
            p++;
        }

        int xsum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(getbit(nums[i],p))
            {
                xsum=xsum^nums[i];
            }
        }
        vector<int> v1;
        v1.push_back(xsum);
        v1.push_back(xsum^xorsum);
        return v1;


    }
};
