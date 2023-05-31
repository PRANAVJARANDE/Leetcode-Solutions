class Solution {
public:

    bool isvowel(char ch)
    {
        if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A'|| ch=='E'|| ch=='I'|| ch=='O'|| ch=='U')
        {
            return 1;
        }
        return 0;
    }


    int maxVowels(string s, int k) 
    {
        int n=s.size();
        int m=0;
        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i]))
            {
                m++;
            }
        }
        
        int c=m;
        for(int i=k;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                c++;
            }
            if(isvowel(s[i-k]))
            {
                c--;
            }
            m=max(m,c);
        }
        return m;
        
    }
};
