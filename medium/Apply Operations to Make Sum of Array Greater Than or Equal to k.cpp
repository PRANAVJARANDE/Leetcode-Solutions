class Solution {
public:
    
    int minOperations(int k) 
    {
        int ans=INT_MAX;
        for(int i=0;i<=k;i++)
        {
            int gh=ceil((double)k/((double)i+1));
            int tans=i+gh-1;
            ans=min(ans,tans);
        }
        return ans;
    }
};
