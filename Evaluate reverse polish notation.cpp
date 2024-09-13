class Solution {
public:
    int evalRPN(vector<string>& s) 
    {
        stack<int> s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!="+" && s[i]!="-" && s[i]!="/" && s[i]!="*")
            {
                int a=stoi(s[i]);
                s1.push(a);
            }
            else
            {
                int x=s1.top();
                s1.pop();
                int y=s1.top();
                s1.pop();

                if(s[i]=="+")
                {
                    s1.push(x+y);
                }
                else if(s[i]=="-")
                {
                    s1.push(y-x);
                }
                else if(s[i]=="*")
                {
                    s1.push(x*y);
                }
                else if(s[i]=="/")
                {
                    s1.push(y/x);
                }


            }
        }

        return s1.top();
    }
};
