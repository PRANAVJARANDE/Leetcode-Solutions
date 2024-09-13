class Solution {
public:
    bool detectCapitalUse(string s) 
    {
        int sm=0;
        int bm=0;

        bool fc=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<='Z' && s[i]>='A')
            {
                if(i==0)
                {
                    fc=1;
                }
                bm++;
            }
            else
            {
                sm++;
            }
        }
        if(bm==1 && fc==1)
        {
            return 1;
        }
        if(bm==s.size() || sm==s.size())
        {
            return 1;
        }
        return 0;
        
    }
};
