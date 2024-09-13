class Solution {
public:
    int minTaps(int n, vector<int>& arr) 
    {
        vector<vector<int>> v1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                continue;
            
            int l=max(0,i-arr[i]);
            int r=min(n,i+arr[i]);
            v1.push_back({l,r});
        }
        if(v1.empty())
        {
            return -1;
        }
        int ans=0;
        sort(v1.begin(),v1.end());
        int s=0,e=0,i=0;
        while(e<n)
        {
            while(i<v1.size() && v1[i][0]<=s)
            {
                e=max(e,v1[i][1]);
                i++;
            }
            if(s==e)
            {
                return -1;
            }
            else
            {
                s=e;
                ans++;
            }
        } 
        return ans;
    }
};
