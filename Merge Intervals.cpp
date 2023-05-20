class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&arr) 
    {
        vector<vector<int>> ans;
        int n=arr.size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i][0]>arr[j][0])
                {
                    swap(arr[i][0],arr[j][0]);
                    swap(arr[i][1],arr[j][1]);
                }
            }
        }
        
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]<=ans.back()[1])
            {
                ans.back()[1]=max(arr[i][1],ans.back()[1]);
                continue;
            }
            else
            {
                ans.push_back(arr[i]);
            }

        }
        
        return ans;

    }
};
