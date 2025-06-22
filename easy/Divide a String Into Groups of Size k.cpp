class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int i=0;
        vector<string>ans;
        while(i<s.size())
        {   
            string res;
            int sz=k;
            while(i<s.size() && sz--)
            {
                res.push_back(s[i]);
                i++;
            }
            while(sz>0)
            {
                sz--;
                res.push_back(fill);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
