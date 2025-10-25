class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double>q1;
        double s=0;
        for(auto x:arr)
        {
            q1.push(x);
            s+=x;
        }
        double hf=s/2.0;
        int ans=0;
        while(s>hf)
        {
            auto in=q1.top();
            q1.pop();
            ans++;
            s-=in;
            s+=(in/2.0);
            q1.push(in/2.0);
        }
        return ans;
    }
};
