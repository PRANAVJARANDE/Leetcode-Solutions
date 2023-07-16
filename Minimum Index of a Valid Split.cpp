class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int x: nums)
        {
               m[x]++;
        }
            
        int de=-1;
        int df=0;
            
        for(auto x: m)
        {
                if(x.second*2>n)
                {
                        df=x.second;
                        de=x.first;
                        break;
                }
        }
        int lf=0;
        for(int i=0;i<n;i++)
        {
                if(nums[i]==de)
                {
                        lf++;
                }
                if(lf*2>i+1 && (df-lf)*2>n-i-1)
                {
                        return i;
                }
        }
        return -1;
    }
};
