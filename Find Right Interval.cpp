class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>&nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int si=nums[i][0];
            int ei=nums[i][1];
            int ind=nums[i][2];

            int s=0,e=n-1;
            int a=-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                int sj=nums[mid][0];
                int ej=nums[mid][1];

                if(sj>=ei)
                {
                    a=mid;
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            ans[ind] = (a != -1) ? nums[a][2] : -1;
        }
        return ans;
    }
};
