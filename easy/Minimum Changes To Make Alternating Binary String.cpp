class Solution {
public:
    int minOperations(string s) 
    {
        int z1=0,o1=0;
        int z2=0,o2=0;

        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                if(s[i]=='0')z1++;
                else o1++;
            }
            else
            {
                if(s[i]=='0')z2++;
                else o2++;
            }
        }
        return min(z1+o2,z2+o1);
    }   
};
