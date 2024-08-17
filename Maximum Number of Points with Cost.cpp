class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        for(int c=0;c<m;c++)
        {
            dp[0][c]=a[0][c];
        }

        for(int i=1;i<n;i++){
            vector<long long>leftMax(m,0),rightMax(m,0);
            leftMax[0]=dp[i-1][0];
            for(int c=1;c<m;c++){
                leftMax[c]=max(leftMax[c-1],dp[i-1][c]+c);
            }

            rightMax[m-1]=dp[i-1][m-1]-(m-1);
            for(int c=m-2;c>=0;c--){
                rightMax[c]=max(rightMax[c+1],dp[i-1][c]-c);
            }

            for(int c=0;c<m;c++) {
                dp[i][c]=a[i][c]+max(leftMax[c]-c,rightMax[c]+c);
            }
        }

        long long ans = 0;
        for (int c=0;c<m;c++){
            ans= max(ans, dp[n-1][c]);
        }
        return ans;
    }
};
