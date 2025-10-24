class Solution {
public:
    bool isPossible(vector<int>& a, int k) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(auto x : a)
        {
            while(!q.empty() && q.top().first + 1 < x)
            {
                if(q.top().second < k) return 0;
                q.pop();
            }

            if(q.empty() || q.top().first == x)
            {
                q.push({x, 1});
            }
            else 
            {
                auto pr = q.top();
                q.pop();
                q.push({x, pr.second + 1});
            }
        }

        while(!q.empty())
        {
            if(q.top().second < k) return 0;
            q.pop();
        }
        return 1;
    }
};
