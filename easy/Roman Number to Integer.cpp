class Solution {
  public:
  
    int mappings(char ch)
    {
        if(ch=='I')return 1;
        else if(ch=='V')return 5;
        else if(ch=='X')return 10;
        else if(ch=='L')return 50;
        else if(ch=='C')return 100;
        else if(ch=='D')return 500;
        else return 1000;
    }
  
    int romanToDecimal(string &s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;)
        {
            if(i+1<n)
            {
                if(mappings(s[i])<mappings(s[i+1]))
                {
                    int res=mappings(s[i+1])-mappings(s[i]);
                    ans+=res;
                    //cout<<i<<" "<<ans<<endl;
                    i+=2;
                }
                else
                {
                    ans+=mappings(s[i]);
                    i++;
                }   
            }
            else
            {
                ans+=mappings(s[i]);
                i++;
            }
            
        }
        return ans;
        
    }
};
