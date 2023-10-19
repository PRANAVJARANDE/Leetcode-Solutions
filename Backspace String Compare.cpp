class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                k--;
                if(k<0)
                {
                    k=0;
                }
            }   
            else
            {
                s[k]=s[i];
                k++;
            }
        }
        int k2=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#')
            {
                k2--;
                if(k2<0)
                {
                    k2=0;
                }
            }   
            else
            {
                t[k2]=t[i];
                k2++;
            }
        }
        if(k==k2)
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]!=t[i])
                {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
};
