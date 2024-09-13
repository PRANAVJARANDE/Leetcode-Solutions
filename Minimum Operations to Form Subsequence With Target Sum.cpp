class Solution {
public:
    int minOperations(vector<int>& nums, int t) 
    {
        long long s=0;
        priority_queue<int>q1;
        for(int x: nums)
        {
            s+=x;
            q1.push(x);
        }

        if(t>s)
        {
            return -1;
        }

        int sp=0;
        while(t>0)
        {
            int k=q1.top();
            q1.pop();
            s-=k;
            if(k>t && s<t)
            {
                sp++;
                s+=k;
                q1.push(k/2);
                q1.push(k/2);
            }
            else if(k<=t)
            {
                t-=k;
            }

            if(q1.empty() && t!=0)
            {
                if(k>t && k!=1)
                {
                    sp++;
                    q1.push(k/2);
                    q1.push(k/2);
                }
                else
                {
                    return -1;
                }
            }
        }
        return sp;
    }
};
