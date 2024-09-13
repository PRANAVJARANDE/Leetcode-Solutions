class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string> s1;
        for(auto x: paths) s1.insert(x[0]);

        for(auto x: paths)
        {
            if(s1.find(x[1])==s1.end())
            {
                return x[1];
            }
        }
        return "";
    }
};
