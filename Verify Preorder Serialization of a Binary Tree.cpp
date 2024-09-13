class Solution {
public:
    bool isValidSerialization(string s) 
    {
        s=s+',';
        stack<char> s1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==',' || s[i+1]!=',')
            {
                continue;
            }
            while(!s1.empty() && s1.top()=='#' && s[i]=='#')
            {
                s1.pop();
                if(s1.empty())
                {
                    return 0;
                }
                s1.pop();
                
            }
            s1.push(s[i]);
        }
        if(s1.size()==1 && s1.top()=='#')
        {
            return 1;
        }
        return 0;
    }
};
