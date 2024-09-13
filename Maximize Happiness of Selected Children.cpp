class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) 
    {
        int n=a.size();
        long long ans=0;
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<k;i++)
        {
            if(a[i]-i>=0)ans+=a[i]-i;
            else break;
        }
        return ans;
    }
};
