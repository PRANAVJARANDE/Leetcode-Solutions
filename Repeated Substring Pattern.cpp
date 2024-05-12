class Solution {
public:
    int n;
    bool che(string &s,int k)
    {
        for(int i=0;i<n-k;i++)
        {
            if(s[i]!=s[i+k])return 0;
        }
        return 1;
    }

    bool repeatedSubstringPattern(string s) 
    {
        n=s.size();
        if(n==1)return 0;
        bool b=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                b=0;
                break;
            }
        }
        if(b==1)
        {
            return 1;
        }

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                int op1=i;
                int op2=n/i;
                if(che(s,op1) || che(s,op2))
                {
                    return 1;
                }
            }
        }
        return 0;       
    }
};
