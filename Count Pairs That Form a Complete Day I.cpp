class Solution {
public:
    int countCompleteDayPairs(vector<int>& a) 
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s=a[i]+a[j];
                if(s%24==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
