class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& arr) 
    {
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++)
        {
            ans=max(ans,arr[i+1][0]-arr[i][0]);
        }
        return ans;
    }
};
