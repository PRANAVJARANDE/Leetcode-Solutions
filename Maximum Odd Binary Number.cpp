class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int in=0;
        for(char x: s)
            if(x=='1')in++;

        if(in==0)return s;
        in--;
        int n=s.size();
        s[n-1]='1';
        for(int i=0;i<in;i++)s[i]='1';
        for(int i=in;i<n-1;i++)s[i]='0';
        return s;
        
    }
};
