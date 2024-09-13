class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        vector<int> v1;
        stack<int> s1;
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            if(x==')')
            {
                if(!s1.empty())s1.pop();
                else v1.push_back(i);
            }
            else if(x=='(')
            {
                s1.push(i);
            }
        }

        while(!s1.empty())
        {
            v1.push_back(s1.top());
            s1.pop();
        }

        string ans="";
        sort(v1.begin(),v1.end());
        int in=0;
        for(int i=0;i<s.size();i++)
        {
            if(in<v1.size() && i==v1[in])
            {
                in++;
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};
