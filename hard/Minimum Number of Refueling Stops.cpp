class Solution {
public:

    int n;
    int minRefuelStops(int tar, int st, vector<vector<int>>& a) 
    {
        n=a.size();
        int in=0;
        int pos=st;
        int ans=0;
        priority_queue<int>q1;
        while(pos<tar)
        {
            while(in<n && a[in][0]<=pos)
            {
                q1.push(a[in][1]);
                in++;
            }
            if(q1.empty())return -1;
            int maxi=q1.top();
            q1.pop();
            ans++;
            pos+=maxi;
        }
        return ans;
    }
};
