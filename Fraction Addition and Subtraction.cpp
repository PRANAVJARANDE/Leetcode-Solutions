class Solution {
public:
    string fractionAddition(string s) {
        int n1=0,d1=1;
        int i=0;
        int n=s.size();
        for(int i=0;i<n;)
        {
            bool minus=0;
            if(s[i]=='-' || s[i]=='+')
            {
                if(s[i]=='-')minus=1;
                i++;
            }
            int num=0;
            if(i+1<n && s[i]=='1' && s[i+1]=='0')
            {
                num=10;
                i+=2;
            }
            else
            {
                num=s[i]-'0';
                i++;
            }
            if(minus)num=-num;
            if(i<n && s[i]=='/')i++;
            int den=1;
            if(i+1<n && s[i]=='1' && s[i+1]=='0')
            {
                den=10;
                i+=2;
            }
            else
            {
                den=s[i]-'0';
                i++;
            }
            n1=(n1*den)+(d1*num);
            d1*=den;
            int gc=__gcd(abs(n1),d1);
            n1/=gc;
            d1/=gc;

        }
        return to_string(n1)+'/'+to_string(d1);

    }
};
