class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++)
        {
            int y=nums[i];
            while(y)
            {
                if(y%2)cnt[i]++;
                y/=2;
            }
        }
        int pmaxi=INT_MIN;
        int i=0;
        while(i<n)
        {
            int maxi=nums[i];
            int mini=nums[i]; 
            int tar=cnt[i];
            while(i<n && tar==cnt[i])
            {   
                maxi=max(maxi,nums[i]);
                mini=min(mini,nums[i]);
                i++;
            }
            cout<<i<<endl;
            if(mini<pmaxi)return 0;
            cout<<i<<endl;
            pmaxi=maxi;
        }
        return 1;
    }
};
