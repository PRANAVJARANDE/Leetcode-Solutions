class Solution {
public:
        
    void helper(int &ans,vector<vector<int>> &nums,int in,vector<vector<int>>&one)
    {
        int n=nums.size();
        if(in==n-1)
        {
                int dist=0;
            for(int i=0;i<n;i++)
            {
                  dist+=abs(nums[i][0]-one[i][0])+abs(nums[i][1]-one[i][1]);
            }
            ans=min(ans,dist);
            return;
        }
        for(int i=in;i<n;i++)
        {
            swap(nums[i],nums[in]);
            helper(ans,nums,in+1,one);
            swap(nums[i],nums[in]);
        }
    }
        
        
    int minimumMoves(vector<vector<int>>& arr) 
    {
        vector<vector<int>> zer;
            vector<vector<int>> one;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                        if(arr[i][j]==0)
                        {
                                zer.push_back({i,j});
                        }
                        if(arr[i][j]>1)
                        {
                                for(int h=1;h<arr[i][j];h++)
                                {
                                        one.push_back({i,j});
                                }
                        }
                }
            }
            
            int ans=INT_MAX;
            helper(ans,zer,0,one);
            return ans;
    }
};
