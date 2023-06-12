class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> v1;
        int i=0,j=0;

        while(j<nums.size())
        {
            if(j+1<nums.size() && nums[j]+1==nums[j+1])
            {
                j++;
            }
            else
            {
                string ans="";
                if(i==j)
                {
                    v1.push_back(to_string(nums[i]));
                }
                else
                {
                    ans=to_string(nums[i])+"->"+to_string(nums[j]);
                    v1.push_back(ans);
                }
                j++;
                i=j;
            }
        }
        return v1;
    }
};
