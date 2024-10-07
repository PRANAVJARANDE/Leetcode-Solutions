class Solution {
public:
    int minLength(string s) {
        stack<char>s1;
        for(char x:s)
        {
            if(x=='B' && !s1.empty() && s1.top()=='A')s1.pop();
            else if(x=='D' && !s1.empty() && s1.top()=='C')s1.pop();
            else
            {
                s1.push(x);
            }
        }
        return (int)s1.size();
    }
};
