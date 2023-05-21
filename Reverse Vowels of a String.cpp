class Solution {
public:

    bool isvowel(char ch)
    {
        if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ||ch=='A' ||ch=='E' ||ch=='I' ||ch=='O' ||ch=='U')
        {
            return 1;
        }
        return 0;
    }

    string reverseVowels(string s) 
    {
        int p1=0;
        int p2=s.size()-1;

        while(p1<p2)
        {
            if(isvowel(s[p1]) && isvowel(s[p2]))
            {
                swap(s[p1],s[p2]);
                p1++;
                p2--;
            }
            else if(!isvowel(s[p1]))
            {
                p1++;
            }
            else if(!isvowel(s[p2]))
            {
                p2--;
            }
        }
        return s;
    }
};
