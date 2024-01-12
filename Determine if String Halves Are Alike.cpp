class Solution {
public:

    bool isvov(char x)
    {
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
        {
            return 1;
        }
        return 0;
    }
 
    bool halvesAreAlike(string s) 
    {
        int n=s.size();
        int c1=0,c2=0;
        for(int i=0;i<n/2;i++)
        {
            if(isvov(s[i]))
            {
                c1++;
            }
        }
        for(int i=n/2;i<n;i++)
        {
            if(isvov(s[i]))
            {
                c2++;
            }
        }
        if(c1==c2)
        {
            return 1;
        }
        return 0;
    }
};
