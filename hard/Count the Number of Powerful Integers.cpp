class Solution {
public:

    long long helper(int in,int b,string tc,string s,int l)
    {
        if(in>=16)return 1;
        int snum=s[in]-'0';
        int pt=16-tc.size();
        if(in>=pt)
        {
            int sind=in-pt; 
            int yc=tc[sind]-'0';
            if(yc>l)return 0;
            if(b==0)
            {
                if(yc>snum)return 0;
                else if(yc==snum)return helper(in+1,0,tc,s,l);
                else return helper(in+1,1,tc,s,l);
            }
            else
            {
                return helper(in+1,1,tc,s,l);
            }
        }

        if(b==0)
        {
            long long op1=0;
            if(snum<=l)op1=helper(in+1,0,tc,s,l);
            long long op2=((long long)min(snum,l+1))*helper(in+1,1,tc,s,l);
            return op1+op2;
        }
        return ((long long)(l+1))*helper(in+1,1,tc,s,l);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string ds) 
    {
        start--;
        string s(16,'0'),e(16,'0');
        for(int i=15;i>=0;i--)
        {
            int rs=start%10;
            start/=10;
            int rf=finish%10;
            finish/=10;
            s[i]=rs+'0';
            e[i]=rf+'0';
        }
        long long ans1=helper(0,0,ds,e,limit);
        long long ans2=helper(0,0,ds,s,limit);
        return ans1-ans2;
    }
};

