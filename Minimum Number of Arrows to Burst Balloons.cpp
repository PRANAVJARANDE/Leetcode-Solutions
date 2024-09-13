class Solution {
public:

    static bool cmp(const std::vector<int>& a, const std::vector<int>& b) 
    {
        return a[1] < b[1]; 
    }

    int findMinArrowShots(vector<vector<int>>& arr) 
    {
        int ans=1;
        sort(arr.begin(),arr.end(),cmp);
        int ar=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]>ar)
            {
                ans++;
                ar=arr[i][1];
            }
        }
        return ans;        
    }
};
