class Solution {
public:
    pair<int, int> ana(string &s) 
    {
        int xc=0;
        int a=0;
        int i=0;
        bool sign=1;
        int num=0;
        while(i<s.size()) 
        {
            if(s[i]=='-')
            {
                sign=0;
                i++;
            }
            else if(s[i]=='+')
            {
                sign=1;
                i++;
            }
            else if(sign==1)
            {
                num=0;
                bool flag=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    flag=1;
                    num=num*10+(s[i]-'0');
                    i++;
                }

                if(i<s.size()  && s[i]=='x')
                {
                    if(flag==1)
                        xc+=num;
                    else
                        xc++;

                }
                else
                {
                    a+=num;
                    if(i<s.length())
                    {
                        if(s[i]=='-')sign=0;
                        else sign=1;
                    }
                }
                i++;
            }
            else if(sign==0)
            {
                num=0;
                bool flag=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    flag=1;
                    num=num*10+(s[i]-'0');
                    i++;
                }
                if(i<s.size()  && s[i]=='x')
                {
                    if(flag==1)
                        xc-=num;
                    else
                        xc--;
                }
                else
                {
                    a-=num;
                    if(i<s.length())
                    {
                        if(s[i]=='-')sign=0;
                        else sign=1;
                    }
                }
                i++;
            }
        }
        return { xc, a };
    }

    string solveEquation(string eq) {
        int in = eq.find("=");
        string s1 = eq.substr(0, in);
        string s2 = eq.substr(in + 1);

        pair<int, int> p1 = ana(s1);
        pair<int, int> p2 = ana(s2);

        int x1 = p1.first, x2 = p2.first, a1 = p1.second, a2 = p2.second;

        if (x1 == x2) {
            if (a1 == a2)
                return "Infinite solutions";
            else
                return "No solution";
        }
        else {
            int ans = (a2 - a1) / (x1 - x2);
            return "x=" + to_string(ans);
        }
    }
};
