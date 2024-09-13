class Solution {
public:

    bool helper(int n,int k,int mid,int b,vector<int>&st,vector<int>&comp,vector<int>&co)
    {
        long long ans=0;
        vector<long long> temp;
        for(int i=0;i<n;i++)
        {
            long long req=mid*(long long)comp[i];
            temp.push_back(req);
        }
        for(int i=0;i<n;i++)
        {
            if(temp[i]-st[i]>0)
            {
                temp[i]=temp[i]-st[i];
            }
            else
            {
                temp[i]=0;
            }
            ans=ans+temp[i]*co[i];
            if(ans>b)
            {
                return 0;
            }
        }
        if(ans>b)
        {
            return 0;
        }
        return 1;
    }

    int maxNumberOfAlloys(int n, int k, int b, vector<vector<int>>& comp, vector<int>& st, vector<int>& co) 
    {
        int ans=0;
        for(int i=0;i<k;i++)
        {
            vector<int>v1 =comp[i];
            int a=0,l=0,r=1e9;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(helper(n,k,mid,b,st,v1,co))
                {
                    l=mid+1;
                    a=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            ans=max(ans,a);
        }
        return ans;
    }
};
