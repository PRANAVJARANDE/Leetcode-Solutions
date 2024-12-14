class Solution {
public:

    bool check(multiset<int>&s1)
    {
        int mini=*s1.begin();
        int maxi=*s1.rbegin();
        if(maxi-mini<=2)return 0;
        return 1;
    }

    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        multiset<int> s1;
        int l=0;
        for(int i=0;i<n;i++)    
        {
            s1.insert(nums[i]);
            while(check(s1))
            {
                s1.erase(s1.find(nums[l]));
                l++;
            }
            int req=i-l+1;
            ans+=req;
        }
        return ans;
    }
};
