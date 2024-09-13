class Solution {
public:
    
    bool isVowel(char c) {
    c = std::tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
    }
    
    
    bool isValid(string s) {
        int n=s.size();
        if(n<3)return 0;
        bool b1=0,b2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='@' || s[i]=='#' || s[i]=='$')return 0;
            if(s[i]<='z' && s[i]>='a')
            {
                if(isVowel(s[i]))b1=1;
                else b2=1;
            }
            else if(s[i]<='Z' && s[i]>='A')
            {
                if(isVowel(s[i]))b1=1;
                else b2=1;
            }
            
        }
        if(b1 && b2)return 1;
        return 0;
    }
};
