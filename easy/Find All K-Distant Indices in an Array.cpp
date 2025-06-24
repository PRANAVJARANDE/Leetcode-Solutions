class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();    
        vector<int>v1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)v1.push_back(i);
        }
        vector<int>ans;
        int i=0;
        for(auto x:v1)
        {
            int l=x-k;
            int r=min(x+k,n-1);
            i=max(i,l);
            while(i<=r)
            {
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};
