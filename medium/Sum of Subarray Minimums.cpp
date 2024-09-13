class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> prev(n,-1),nxt(n,n);
        stack<int> s1,s2;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && nums[s1.top()]>=nums[i])
            {
                s1.pop();
            }

            if(!s1.empty())
            {
                prev[i]=s1.top();
            }
            s1.push(i);
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && nums[s2.top()]>nums[i])
            {
                s2.pop();
            }

            if(!s2.empty())
            {
                nxt[i]=s2.top();
            }
            s2.push(i);
        }

        long long ans=0;
        long long m=1e9+7;
        for(int i=0;i<n;i++)
        {
            int l1=i-prev[i];
            int l2=nxt[i]-i;
            ans= ((ans%m) + ((l1%m)*(l2%m)*(nums[i]%m))%m)%m;
        }
        return ans;
        
    }
};
