class Solution {
public:
    long long countSubstrings(string s, char c) 
    {
        long long n=0;
        for(char x:s)
        {
            if(x==c)n++;
        }
        long long ans=(n*(n+1))/2;
        return ans;
    }
};
