class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int t;
        vector<vector<int>> v1;
        set<vector<int>> s1;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            t=-nums[i];
            int p1=i+1;
            int p2=nums.size()-1;

            while(p1<p2)
            {
            int s=nums[p1]+nums[p2];
            if(s==t)
            {
                s1.insert({nums[i],nums[p1],nums[p2]});
                p1++;
                p2--;
            }
            else if(s>t)
            {
                p2--;
            }
            else
            {
                p1++;
            }

            }

        }
        

        for(auto x:s1)
        {
            v1.push_back(x);
        }

        return v1;
    }
};
