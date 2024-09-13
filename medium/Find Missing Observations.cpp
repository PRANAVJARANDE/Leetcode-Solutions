class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        int m=a.size();
        int sum=(n+m)*mean;
        for(int x:a)
        {
            sum-=x;
        }
        int req=sum/n;
        if(sum<0 || sum>6*n)return {};
        vector<int> ans(n,req);
        sum=sum%n;
        int i=0;
        while(sum>0)
        {
            ans[i]++;
            sum--;
            i++;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]>=7 || ans[i]<=0)return {};
        }
        return ans;
    }
};
