class Solution {
public:
    int largestCombination(vector<int>& a) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int res=0;
            for(int x:a)
            {
                if((x & (1<<i)))
                {
                    res++;
                }
            }
            ans=max(ans,res);
        }
        return ans;
    }
};
