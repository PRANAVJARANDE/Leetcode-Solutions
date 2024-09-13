class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
        set<int> s1;
            for(int x: nums)
            {
                s1.insert(x);
            }
            for(int i=0;i<mf.size();i++)
            {
                s1.erase(mf[i]);
                s1.insert(mt[i]);
            }
            vector<int> ans;
            for(int x:s1)
            {
                ans.push_back(x);
            }
            return ans;
    }
};
