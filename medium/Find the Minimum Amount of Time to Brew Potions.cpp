class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) 
    {
        long long m=mana.size();
        long long n=skill.size();
        vector<vector<long long>>a(m,vector<long long>(n,0));
        for(long long i=0;i<m;i++)
        {
            for(long long j=0;j<n;j++)
            {
                long long p1=0,p2=0;
                if(i-1>=0)p1=a[i-1][j];
                if(j-1>=0)p2=a[i][j-1];
                a[i][j]=max(p1,p2)+((long long)mana[i]*(long long)skill[j]);
            }
            for(long long j=n-2;j>=0;j--)a[i][j]=a[i][j+1]-mana[i]*skill[j+1];
        }
        long long res=a[m-1][n-1];
        return res;
    }
};
