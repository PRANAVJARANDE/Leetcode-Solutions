class Solution {
public:

    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int pr=0;
        priority_queue<long long,vector<long long>,greater<long long>>q1;
        q1.push(1);
        while(pr<n)
        {
            long long in=q1.top();
            while(!q1.empty() && q1.top()==in)q1.pop();
            pr++;
            if(pr==n)return in;
            for(auto x:primes)q1.push(in*x);
        }
        return q1.top();
    }
};
