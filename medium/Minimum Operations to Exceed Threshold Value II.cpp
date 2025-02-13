class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>q1;
        for(auto x:nums)q1.push(x);
        int ans=0;
        while(q1.top()<k)
        {
            long long p1=q1.top();
            q1.pop();
            long long p2=q1.top();
            q1.pop();
            long long tp=2*min(p1,p2)+max(p1,p2);
            q1.push(tp);
            ans++;
        }
        return ans;


    }
};
