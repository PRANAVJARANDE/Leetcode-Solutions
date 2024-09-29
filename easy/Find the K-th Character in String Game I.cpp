class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k)
        {
            string temp="";
            for(char x: s)
            {
                char ch;
                if(x=='z')ch='a';
                ch=x+1;
                temp+=ch;
            }
            s+=temp;
        }
        return s[k-1];
    }
};
