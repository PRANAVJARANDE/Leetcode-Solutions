class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q1;
        for(auto x: nums)q1.push(x);
        long long ans=0;
        while(k--)
        {
            int d=q1.top();
            q1.pop();
            ans+=d;
            q1.push(ceil((double)d/3.0));
        }
        return ans;
    }
};
