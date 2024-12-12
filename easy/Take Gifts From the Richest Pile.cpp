class Solution {
public:
    long long pickGifts(vector<int>& a, int k) {
        priority_queue<int> q1;
        long long s=0;
        for(int x:a)
        {
            q1.push(x);
            s+=x;
        }
        while(k--)
        {
            int tp=q1.top();
            q1.pop();
            s-=tp;
            tp=sqrt(tp);
            s+=tp;
            q1.push(tp);
        }
        return s;
    }
};
