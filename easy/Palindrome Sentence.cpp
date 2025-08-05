class Solution {
  public:
    
    bool not_alpha(char s)
    {
         if('a'<=s && s<='z')return 0;
         if('0'<=s && s<='9')return 0;
         return 1;
    }
  
    bool isPalinSent(string &s) 
    {
        for(char &c:s)c=tolower(c);
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            while(i<j && not_alpha(s[i]))i++;
            while(i<j && not_alpha(s[j]))j--;
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
};
