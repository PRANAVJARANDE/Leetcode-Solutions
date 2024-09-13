class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int> cha(n+1,0);
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(cha[i]==1)
            {
                p=!p;
            }
            if(nums[i]==p)
            {
                ans++;
                if(p==0)p=1;
                else p=0;
                if(i+k>n)return -1;
                cha[i+k]=1;
            }
        }
        return ans;
    }
};
