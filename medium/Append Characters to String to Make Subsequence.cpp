class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int in=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[in])
            {
                in++;
                if(in==t.size())return 0;
            }
        }
        return (int)t.size()-in;
        
    }
};
