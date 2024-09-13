class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t="";
            for(string x: words)
            {
                    t=t+x[0];
            }
            if(t==s)
            {
                    return 1;
            }
            return 0;
    }
};
