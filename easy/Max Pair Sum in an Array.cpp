class Solution {
public:
        
        int getans(string s)
        {
                int ma=INT_MIN;
                for(int i=0;i<s.size();i++)
                {
                        if(ma<s[i]-'a')
                        {
                                ma=s[i]-'a';
                        }
                }
                return ma;
        }
        
        
    int maxSum(vector<int>& nums) 
    {
            vector<int> temp;
            for(int x: nums)
            {
                temp.push_back(getans(to_string(x)));
            }
        int n=nums.size(),ans=-1;
            for(int i=0;i<n;i++)
            {
                    for(int j=i+1;j<n;j++)
                    {
                            if(temp[i]==temp[j])
                            {
                                    ans=max(ans,nums[i]+nums[j]);
                            }
                    }
            }
        return ans;
    }
};
