class Solution {
public:

    int n,m;
    bool check(int in,vector<int>& pt, vector<vector<int>>& a)
    {
        vector<int>rc(n,0),cc(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pt[a[i][j]]<=in)
                {
                    rc[i]++;
                    cc[j]++;
                    if(rc[i]==m)return 1;
                    if(cc[j]==n)return 1;
                }
            }
        }
        return 0;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();

        vector<int>pt(arr.size()+1,0);
        for(int i=0;i<arr.size();i++)
        {
            pt[arr[i]]=i;
        }

        int l=0,r=arr.size()-1;
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,pt,a))
            {
                ans=mid;
                r=mid-1;
            }
            else    
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
