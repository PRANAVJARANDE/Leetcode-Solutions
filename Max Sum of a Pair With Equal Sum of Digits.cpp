class Solution {
public:

    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> m;
        for(int x: nums)
        {
            int k=getSum(x);
            m[k].push(x);
            if(m[k].size()>2)
            {
                m[k].pop();
            }
        }
        int ans=-1;
        for(auto x: m)
        {
            if(x.second.size()<2)
            {
                continue;
            }
            int a=x.second.top();
            x.second.pop();
            ans=max(ans,a+x.second.top());
        }
        return ans;
    }
};
