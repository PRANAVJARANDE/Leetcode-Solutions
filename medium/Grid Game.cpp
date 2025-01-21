class Solution {
public:
    long long gridGame(vector<vector<int>>& a) {
        int n=a[0].size();
        vector<long long>ps(n,0),ns(n,0);
        for(int i=0;i<n;i++)
        {
            ps[i]=a[1][i];
            if(i-1>=0)ps[i]+=ps[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            ns[i]=a[0][i];
            if(i+1<n)ns[i]+=ns[i+1];
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            long long op1=0,op2=0;
            if(i-1>=0)op1=ps[i-1];
            if(i+1<n)op2=ns[i+1];
            long long res=max(op1,op2);
            ans=min(ans,res);
        }
        return ans;
    }
};
