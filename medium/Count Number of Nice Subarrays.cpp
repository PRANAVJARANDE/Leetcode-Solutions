class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        vector<int> v1;
        int n = nums.size();
        v1.push_back(-1);
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] % 2 == 1) 
                v1.push_back(i);
        }
        v1.push_back(n);
        int ans = 0;
        for (int i = 1; i+k<v1.size(); i++) 
        {
            int left_count = v1[i] - v1[i - 1];
            int right_count = v1[i + k] - v1[i + k - 1];
            ans += left_count * right_count;
        }
        return ans;
    }
};
