class Solution {
public:
    string merge(string a, string b) {
        int bs = b.size();
        if(a.find(b)!=string :: npos)
        {
                return a;
        }
        if(b.find(a)!=string :: npos)
        {
                return b;
        }
        for (int i = 0; i < a.size(); i++) 
        {
            string h = a.substr(i);
            if (b.find(h) == 0) {
                return a.substr(0, i) + b;
            }
        }
        return a + b;
    }

    void helper(string a, string b, string c, string &ans, int &ml) {
        string merged1 = merge(a, b);
        string merged2 = merge(a, c);
        string merged3 = merge(b, c);

        string merged = merge(merged1, c);
        int k = merged.size();
        if (k < ml || (k == ml && merged.compare(ans) < 0)) {
            ans = merged;
            ml = k;
        }
        
    }

    string minimumString(string a, string b, string c) {
        int ml = INT_MAX;
        string ans = "";
           
        helper(a, b, c, ans, ml);
        helper(a, c, b, ans, ml);
        helper(b, a, c, ans, ml);
        helper(b, c, a, ans, ml);
        helper(c, a, b, ans, ml);
        helper(c, b, a, ans, ml);

        return ans;
    }
};
