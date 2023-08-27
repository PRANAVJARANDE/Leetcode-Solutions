class Solution {
public:
    int furthestDistanceFromOrigin(string s) 
    {
            int lc=0,rc=0,uc=0;
            for(int i=0;i<s.size();i++)
            {
                    if(s[i]=='L')
                    {
                            lc++;
                    }
                    else if(s[i]=='R')
                    {
                            rc++;
                    }
                    else
                    {
                            uc++;
                    }
            }
            return abs(lc-rc)+uc;
    }
};
