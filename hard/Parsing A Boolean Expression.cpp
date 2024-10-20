class Solution {
public:

    int n;
    bool helper(int &in,string &s)
    {
        bool tp=0,fp=0;
        char op=s[in];
        in+=2;
        while(s[in-1]!=')')
        {
            if(s[in]=='t')tp=1;
            else if(s[in]=='f')fp=1;
            else
            {
                bool res=helper(in,s);
                if(res)tp=1;
                else fp=1;
            }
            in+=2;
        }
        in--;
        if(op=='|')return tp;
        else if(op=='&')return !fp;
        if(tp)return 0;
        return 1;
    }

    bool parseBoolExpr(string s) {
        n=s.size();
        int in=0;
        return helper(in,s);
    }
};
