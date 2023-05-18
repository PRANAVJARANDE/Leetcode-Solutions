class Solution {
public:
    string addBinary(string a, string b) 
    {
        int l1=a.size();
        int l2=b.size();

        if(l1<l2)
        {
            while(l1!=l2)
            {
                a='0'+a;
                l1++;
            }
        }
        else if(l1>l2)
        {
            while(l1!=l2)
            {
                b='0'+b;
                l2++;
            }
        }

        
        string ans="";
        int c=0,r;
        for(int i=l1-1;i>=0;i--)
        {
            
            int s=(a[i]-'0')+(b[i]-'0');
            if(s+c==3)
            {
                c=1;
                r=1;
            }
            else if(s+c==2)
            {
                c=1;
                r=0;
            }
            else if(s+c==1)
            {
                c=0;
                r=1;
            }
            else
            {
                c=0;
                r=0;
            }
            char ch=r+'0';
            ans=ch+ans;
        }
        if(c==1)
        {
            ans='1'+ans;
        }
        return ans;


    }
};
