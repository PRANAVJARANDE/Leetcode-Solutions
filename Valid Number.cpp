class Solution {
public:

    bool isdigi(char ch)
    {
        if(ch<='9' && ch>='0')
        {
            return 1;
        }
        return 0;
    }

    bool isNumber(string s) 
    {
        int i=0;
        int n=s.size();
        if(s[i]=='+' || s[i]=='-')
        {
            i++;
        }
        if(i==n)
        {
            return 0;
        }
        bool b1=0;
        while(i<n && isdigi(s[i]))
        {
            b1=1;
            i++;
        }
        
        if(s[i]=='.')
        {
            if(b1==1)
            {
                i++;
            }
            else
            {
                if(i!=n-1 && isdigi(s[i+1]))
                {
                    i++;
                }
                else
                {
                    return 0;
                }
            }
        }

        while(i<n && isdigi(s[i]))
        {
            b1=1;
            i++;
        }
        if(s[i]=='e' || s[i]=='E')
        { 
            if(i!=n-1 && (s[i+1]=='+' || s[i+1]=='-'))
            {
                i++;
            }
            if(b1==1 && i!=n-1 && (isdigi(s[i+1])))
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        
        while(i<n && isdigi(s[i]))
        {
            i++;
        }
    if(i==n)
    {
        return 1;
    }
    return 0;
    }
};
