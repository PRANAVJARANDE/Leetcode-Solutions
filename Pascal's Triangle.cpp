class Solution {
public:

    int ncr(int n,int r)
    {
        if(r==0)
        {
            return 1;
        }
        if(r>n-r)
        {
            r=n-r;
        }
        
        long long ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(n-i+1)/i;
        }
        return ans;
    }


    vector<int> getRow(int r) 
    {
        vector<int> ans;
        for(int i=0;i<=r;i++)
        {
            ans.push_back(ncr(r,i));
        }
        return ans;
    }

    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> v1;
        for(int i=0;i<n;i++)
        {
            vector<int> ans;
            for(int j=0;j<=i;j++)
            {
                ans.push_back(ncr(i,j));
            }
            v1.push_back(ans);
        }
        return v1;
    }
};
