class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<long long ,long long> m;
        for(int x:nums1)
        {
            if(x%k==0)
            {
                x/=k;
                for(int j=1;j<=sqrt(x);j++)
                {
                    if(x%j==0)
                    {
                        int op1=j;
                        int op2=x/j;
                        if(op1==op2)
                        {
                            m[op1]++;
                        }
                        else
                        {
                            m[op1]++;
                            m[op2]++;
                        }
                    }
                }
            }
        }
        
        long long ans=0;
        for(int y: nums2)
        {
            ans+=m[y];
        }
        return ans;
        
    }
};
