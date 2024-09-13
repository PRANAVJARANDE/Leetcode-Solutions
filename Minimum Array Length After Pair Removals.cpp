class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) 
    {
            unordered_map<int,int> m;
            int n=nums.size();
            int maxi=0;
            for(int i=0;i<nums.size();i++)
            {
                m[nums[i]]++;
                maxi=max(maxi,m[nums[i]]);
            }
            
            int rest=n-maxi;
            if(maxi>rest)
            {
                return maxi-rest;
            }
            if(n%2==1)
            {
                return 1;
            }
            return 0;
    }
};
