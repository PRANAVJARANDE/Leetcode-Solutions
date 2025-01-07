class Solution {
public:
    vector<string> stringMatching(vector<string>& s) {
        set<string>ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=i && s[j].find(s[i])!= string::npos)
                {
                    ans.insert(s[i]);
                    break;
                }
            }
        }
        vector<string>res;
        for(auto x:ans)res.push_back(x);
        return res;
    }
};
