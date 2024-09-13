class Solution {
public:

    int maximumGain(string s, int x, int y) 
    {
        int ans=0;
        int a=0,b=0;
        if(x>y)
        {
            stack<char> s1;
            for(char c:s)
            {
                if(c=='a')
                {
                    a++;
                }
                else if(c=='b')
                {
                    if(a!=0)
                    {
                        a--;
                        ans+=x;
                    }
                    else
                    {
                        b++;
                    }
                }
                else
                {
                    ans+=min(a,b)*y;
                    a=0;
                    b=0;
                }
            }
            ans+=min(a,b)*y;
        }
        else
        {
            stack<char> s1;
            for(char c:s)
            {
                if(c=='b')
                {
                    b++;
                }
                else if(c=='a')
                {
                    if(b!=0)
                    {
                        b--;
                        ans+=y;
                    }
                    else
                    {
                        a++;
                    }
                }
                else
                {
                    ans+=min(a,b)*x;
                    a=0;
                    b=0;
                }
            }
            ans+=min(a,b)*x;
        }
        return ans;
    }
};
