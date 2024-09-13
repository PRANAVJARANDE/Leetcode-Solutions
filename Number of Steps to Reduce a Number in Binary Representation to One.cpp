class Solution {
public:
    int numSteps(string s) 
    {
        int n=s.size();
        int in=n-1;
        int ans=0;
        while(in>=0)
        {
            if(s[in]=='0')
            {
                ans++;
                in--;
            }
            else
            {
                if(in==0)
                {
                    return ans;
                }
                while(in>=0 && s[in]=='1')
                {
                    s[in]='0';
                    in--;
                    ans++;
                }
                if(in<0)
                {
                    ans++;
                    return ans;
                }
                s[in]='1';
                ans++;
            }
        }
        return ans;
    }
};
