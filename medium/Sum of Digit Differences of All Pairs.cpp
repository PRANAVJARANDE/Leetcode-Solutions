class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) 
    {
        long long ans=0;
        long long n=nums.size();
        
        long long x=nums[0];
        long long k=0;
        while(x!=0)
        {
            k++;
            x/=10;
        }
        
        
        for(int z=0;z<k;z++)
        {
            map<long long,long long> m;
            for(int i=0;i<n;i++)
            {
                int rem=nums[i]%10;
                nums[i]/=10;
                m[rem]++;
            }
            vector<long long>v1;
            for(auto x: m)
            {
                v1.push_back(x.second);
            }
            long long gh=0;
            long long c=n;
            for(int i=0;i<v1.size();i++)
            {
                gh+=(c-v1[i])*v1[i];
                c-=v1[i];
            }
            ans+=gh;   
        }
        return ans;
    }
};
