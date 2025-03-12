class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a1=0,a2=0;
        for(auto x:nums)
        {
            if(x<0)a1++;
            else if(x>0)a2++;
        }
        return max(a1,a2);
    }
};
