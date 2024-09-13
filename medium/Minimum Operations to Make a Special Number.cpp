class Solution {
public:
    int minimumOperations(string s) 
    {   
            reverse(s.begin(),s.end());
            int n=s.size();
             int ans=0;
            for(int i=0;i<n;i++)
            {
                    if(s[i]!='0')
                    {
                            ans++;
                    }
            }
            for(int i=0;i<n;i++)
            {
                    if(s[i]=='0' || s[i]=='5')
                    {
                            int del=i;
                            for(int j=i+1;j<n;j++)
                            {
                                if(s[i]=='0')
                                {
                                        if(s[j]=='0' || s[j]=='5')
                                        {
                                                del+=j-i-1;
                                                ans=min(ans,del);
                                                break;
                                        }
                                }
                                else
                                {
                                        if(s[j]=='2' || s[j]=='7')
                                        {
                                                del+=j-i-1;
                                                ans=min(ans,del);
                                                break;
                                        }    
                                }
                            }
                    }
            }
            return ans;
        
    }
};
