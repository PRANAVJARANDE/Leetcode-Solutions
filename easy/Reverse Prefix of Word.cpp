class Solution {
public:
    string reversePrefix(string s, char ch) 
    {
        int n=s.size();
        int i=0;
        for(;i<n;i++)
        {
            if(ch==s[i])break;
        }
        if(i==n)return s;
        i++;
        for(int j=0;j<i/2;j++)
        {
            swap(s[j],s[i-j-1]);
        }
        return s;
        
    }
};
