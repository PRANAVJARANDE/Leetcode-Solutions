class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int c=0,ans=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)c--;
            else c++;

            if(m.find(c)!=m.end())
                ans=max(ans,i-m[c]);
            else m[c]=i;
        }
        return ans;
    }
};
