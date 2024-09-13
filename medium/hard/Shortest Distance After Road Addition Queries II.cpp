class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        set<int> s1;
        for (int i = 0; i < n; i++) {
            s1.insert(i);
        }
    
        for (auto x: q) {
            int u = x[0], v = x[1];
            if(s1.find(u)==s1.end())
            {
                int sz = s1.size();
                ans.push_back(sz-1);
                continue;
            }
            if(s1.find(v)==s1.end())
            {
                int sz = s1.size();
                ans.push_back(sz-1);
                continue;
            }
            auto itr=s1.find(u);
            itr++;
            while(itr!=s1.end() && *itr<v)
            {
                auto temp = itr;
                temp++;
                s1.erase(itr);
                itr = temp;
            }
            int sz = s1.size();
            ans.push_back(sz-1);
        }

        return ans;
    }
};
