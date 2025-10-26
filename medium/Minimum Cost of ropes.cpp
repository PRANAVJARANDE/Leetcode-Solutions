class Solution {
  public:
    int minCost(vector<int>& a) {
        priority_queue<int,vector<int>,greater<int>>q1;
        for(auto x:a)q1.push(x);
        int ans=0;
        while(q1.size()>1)
        {
            int i1=q1.top();
            q1.pop();
            int i2=q1.top();
            q1.pop();
            ans+=i1+i2;
            q1.push(i1+i2);
        }
        return ans;
    }
};
