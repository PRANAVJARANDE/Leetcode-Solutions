class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int k=0;
        int e=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                e++;
            }
            else
            {
                break;
            }
        }


        for(int i=0;i<s.size()-e;i++)
        {
            k++;
            if(s[i]==' ')
            {
                k=0;
            }
        }
        return k;
    }
};
