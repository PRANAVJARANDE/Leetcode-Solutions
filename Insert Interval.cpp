class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& n) 
    {
        vector<vector<int>> ans;
        int nn=arr.size();
        int i=0;
        while(i<nn && arr[i][1]<n[0])
        {
            ans.push_back(arr[i]);
            i++;
        }
        int a=n[0];
        int b=n[1];
        while(i<nn && arr[i][0]<=n[1])
        {
            a=min(a,arr[i][0]);
            b=max(b,arr[i][1]);
            i++;
        }
        ans.push_back({a,b});
        while(i<nn)
        {
            ans.push_back(arr[i]);
            i++;
        }
        return ans;

    }
};
