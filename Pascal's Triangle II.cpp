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
};
