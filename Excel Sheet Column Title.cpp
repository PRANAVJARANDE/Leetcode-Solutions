class Solution {
public:
    string convertToTitle(int n) 
    {
        string s="";
        while(n!=0)
        {
            n--;
            char ch=n%26 +'A';
            s=ch+s;
            n=n/26;
        }
        return s;
    }
};
