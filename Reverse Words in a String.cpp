class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string> s1;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            if(i<s.size()-1 && s[i+1]==' ')
            {
                ans=ans+s[i];
                s1.push(ans);
                ans="";
                continue;
            }
            ans=ans+s[i];
        }    
    
    if(ans!="")
    {
        s1.push(ans);
    }
    
    string h="" ;

    while(!s1.empty())
    {
        h=h+s1.top();
        s1.pop();
        if(s1.empty())
        {
            break;
        }
        h=h+" ";
        
    }
    return h;

    }
};
