class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) 
    {
        int  n=p.size();
        vector<vector<int>> v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=c[i];
            v1[i][1]=p[i];
        }
        sort(v1.begin(),v1.end());
        priority_queue<int> q1;
        int in=0;
        while(k--)
        {
            while(in<n && w>=v1[in][0])
            {
                q1.push(v1[in][1]);
                in++;
            }
            if(!q1.empty())
            {
                w+=q1.top();
                q1.pop();
            }   
        }
        return w;
    }
};
