class Solution {
public:

    bool check(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return 1;
        return 0;
    }

    vector<int> vowelStrings(vector<string>& a, vector<vector<int>>& q) 
    {
        int n=a.size();
        vector<int>psum(n,0);
        for(int i=0;i<n;i++)
        {
            if(check(a[i][0]) && check(a[i][a[i].size()-1]))
            {
                psum[i]++;
            }
        }
        for(int i=1;i<n;i++)
        {
            psum[i]+=psum[i-1];
        }

        int qs=q.size();
        vector<int>ans(qs,0);
        for(int i=0;i<qs;i++)
        {
            int l=q[i][0],r=q[i][1];
            int res=psum[r];
            if(l-1>=0)res-=psum[l-1];
            ans[i]=res;
        }
        return ans;
    }
};
