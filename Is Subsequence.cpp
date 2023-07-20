class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int j=0;
        for(char x: t)
        {
            if(s[j]==x)
            {
                j++;
            }
        }
        if(j==s.size())
            return 1;
        
        return 0;
    }
};
