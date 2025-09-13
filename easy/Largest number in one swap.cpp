class Solution {
  public:
    string largestSwap(string &s) 
    {
        int n=s.size();
        vector<int>nmax(n,0);
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,s[i]-'0');
            nmax[i]=maxi;
        }
        for(int i=0;i<n;i++)
        {
            if(nmax[i]!=(s[i]-'0'))
            {
                for(int j=n-1;j>i;j--)
                {
                    if(s[j]-'0'==nmax[i])
                    {
                        swap(s[i],s[j]);
                        return s;
                    }    
                }
            }
        }
        
        return s;
        
        
    }
};
