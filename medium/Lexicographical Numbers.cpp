class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        set<string> s1;
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            s1.insert(to_string(i));
        }
        for(auto x: s1)
        {
            ans.push_back(stoi(x));
            s1.erase(x);
        }
        return ans;
    }
};
