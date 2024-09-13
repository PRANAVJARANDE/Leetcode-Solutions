class Solution {
public:

    bool check(unordered_map<int,int> & m)
    {
        for(auto x: m)
        {
            if(x.second>=2)
            {
                return 0;
            }
        }
        return 1;
    }

    bool getbit(int n,int i)
    {
        return n & 1<<i;
    }



    int longestNiceSubarray(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int n=nums.size(),ans=0,l=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            {
                if(getbit(nums[i],j))
                {
                    m[j]++;
                }
            }

            while(check(m)==0 && l<=i)
            {
                for(int j=0;j<32;j++)
                {
                    if(getbit(nums[l],j))
                    {
                        m[j]--;
                    }
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
