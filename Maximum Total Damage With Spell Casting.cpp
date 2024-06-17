class Solution {
public:
    
  long long n;
long long helper(long long in,vector<vector<long long>>&v1,vector<long long>&dp)
{
    if(in>=n)return 0;
    if(dp[in]!=-1)return dp[in];
    long long op1=helper(in+1,v1,dp);
    long long nx=in;
    while(nx<n && v1[nx][0]<=v1[in][0]+2)
    {
        nx++;
    }
    long long op2=v1[in][0]*v1[in][1]+helper(nx,v1,dp);
    return dp[in]=max(op1,op2);
}


long long maximumTotalDamage(vector<int>& p) {
    map<long long,long long> m;
    for(auto x:p)
    {
        m[x]++;
    }
    vector<vector<long long>>v1;
    for(auto x: m)
    {
        v1.push_back({x.first,x.second});
    }
    n=v1.size();
    vector<long long> dp(n,-1);
    return helper(0,v1,dp);
}

};
