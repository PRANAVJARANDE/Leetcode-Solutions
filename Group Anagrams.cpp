class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) 
    {
        unordered_map<string,vector<string>> ma;
        for(string s: arr)
        {
            string ts=s;
            sort(s.begin(),s.end());
            ma[s].push_back(ts);
        }
        vector<vector<string>> ans;
        for(auto j: ma)
        {
            ans.push_back(j.second);
        }
        return ans;
    }
};
