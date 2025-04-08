class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,int>m;
        for(int i=n-1;i>=0;i--)
        {
            m[nums[i]]++;
            if(m[nums[i]]==2)
            {
                int ans=(i+1)/3;
                if((i+1)%3!=0)ans++;
                return ans;
            }
        }
        return 0;
    }
};
