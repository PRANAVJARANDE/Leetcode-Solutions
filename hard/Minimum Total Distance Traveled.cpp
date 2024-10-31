class Solution {
public:
    long long INF=(1LL<<40);
    int n,m;
    vector<vector<vector<long long>>> dp;
    long long helper(int in,int f,int cap,vector<int>&robot,vector<vector<int>>&factory)
    {
        if(in>=n)return 0;
        if(f>=m)return INF;
        if (dp[in][f][cap] != -1) return dp[in][f][cap];
        //next factory
        long long op1=helper(in,f+1,0,robot,factory);
        //present factory
        long long op2=INF;
        if(cap+1<=factory[f][1])op2=(abs(robot[in]-factory[f][0]))+helper(in+1,f,cap+1,robot,factory);
        return dp[in][f][cap]=min(op1,op2);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n=robot.size();
        m=factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        dp = vector<vector<vector<long long>>>(n, vector<vector<long long>>(m, vector<long long>(n, -1)));
        long long ans=helper(0,0,0,robot,factory);
        return ans;
    }
};
