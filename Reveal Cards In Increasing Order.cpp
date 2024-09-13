class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& a) 
    {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int> ans(n,0);
        queue<int> q1;
        for(int i=0;i<n;i++)q1.push(i);

        int i=0;
        while(!q1.empty())
        {
            ans[q1.front()]=a[i];
            q1.pop();
            i++;
            if(!q1.empty())
            {
                q1.push(q1.front());
                q1.pop();
            }
        }
        return ans;
    }
};
