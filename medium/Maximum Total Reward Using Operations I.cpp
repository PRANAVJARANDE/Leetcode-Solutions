class Solution {
public:
    int n;
    int maxTotalReward(vector<int>& rv) {
        n=rv.size();
        sort(rv.begin(),rv.end());
        
        vector<int> sum(4001,0);
        sum[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=rv[i];j++)
            {
                if(sum[j]==1 && rv[i]>j)
                {
                    sum[rv[i]+j]=1;
                }
            }
        }
        for(int i=4000;i>=0;i--)
        {
            if(sum[i]==1)return i;
        }
        return 0;
    }
};
