class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        long long n=a.size();
        long long ans=0;
        long long prev=a[0][0];
        for(int i=0;i<n;i++)
        {
            prev=max(prev,(long long)a[i][0]);
            prev+=a[i][1];
            ans+=prev-a[i][0];
        }


        double res=(double)ans/n;
        return res;
    }
};
