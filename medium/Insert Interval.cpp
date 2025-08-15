// GFG Solution 
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &a, vector<int> &ni) {
        vector<vector<int>>ans;
        int nx=ni[0];
        int ny=ni[1];
        int n=a.size();
        
        if(ny<a[0][0])ans.push_back({nx,ny});
        for(int i=0;i<n;i++)
        {
            if(!ans.empty() && ans.back()[1]<nx && ny<a[i][0])
            {
                ans.push_back({nx,ny});
            }
            if(a[i][1]<nx)ans.push_back(a[i]);
            else if(ny<a[i][0])ans.push_back(a[i]);
            else
            {
                int sx=min(nx,a[i][0]);
                int sy=ny;
                while(i<n && a[i][0]<=ny)
                {
                    sy=max(sy,a[i][1]);
                    i++;
                }
                ans.push_back({sx,sy});
                i--;
            }
        }
        if(a[n-1][1]<nx)ans.push_back({nx,ny});
        return ans;
    }
};


//Leetcode Solution
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
