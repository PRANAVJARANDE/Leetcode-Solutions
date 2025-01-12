class Solution {
public:
    bool canBeValid(string s, string l) {
        
        int op=0;
        int ch=0;
        int n=s.size();
        if(n%2)return 0;
        for(int i=0;i<n;i++)
        {
            if(l[i]=='0')ch++;
            else if(s[i]=='(')op++;
            else
            {
                if(op)op--;
                else if(ch)ch--;
                else return 0;
            }
        }
        int cl=0;
        ch=0;
        for(int i=n-1;i>=0;i--)
        {
            if(l[i]=='0')ch++;
            else if(s[i]==')')cl++;
            else
            {
                if(cl)cl--;
                else if(ch)ch--;
                else return 0;
            }
        }
        return 1;
    }
};
