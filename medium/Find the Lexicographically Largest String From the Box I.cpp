class Solution {
public:
    string answerString(string s, int k) {
        if(k==1)return s;
        int n=s.size();
        int ms=n-k+1;
        
        for(int ch='z';ch>='a';ch--)
        {
            string res="";
            for(int i=0;i<n;i++)
            {
                if(s[i]==ch)
                {
                    string tp=s.substr(i,min(ms,n-i));
                    if(tp>res)
                    {
                        res=tp;
                    }
                }
            }
            if(res!="")
            {
                return res;
            }
        }
        return s;
    }
};
