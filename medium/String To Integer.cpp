class Solution {
public:
    int myAtoi(string s) 
    {
        long ans=0;
        int flag=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                break;
            }
            else if(s[i]==' ')
            {
                continue;
            }
            else if(s[i]=='-' && s[i+1]<='9' && s[i+1]>='0')
            {
                flag=0;
                continue;
            }
            else if(s[i]=='+' && s[i+1]<='9' && s[i+1]>='0')
            {
                flag=1;
                continue;
            }
            else if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A'))
            {
                break;
            }

            else if(s[i]<='9' && s[i]>='0')
            {
            int k;
            k=s[i]-'0';
            ans=ans*10+k;
            if(ans>INT_MAX)
            {
                if(flag==1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            } 
            if(!(s[i+1]<='9' && s[i+1]>='0') && i+1<s.size())
            {
                break;
            }
            }
            else
            {
                break;
            }
            




        }

        if(flag==0)
        {
            ans=-ans;
        }
        return ans;
        
    }
};
