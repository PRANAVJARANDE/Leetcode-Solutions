class Solution {
public:

    bool isnum(char c)
    {
        if('0'<=c && c<='9')return 1;
        return 0;
    }


    string helper(int l,int r,string& s)
    {
        string ans="";
        for(int i=l;i<=r;)
        {
            while(i<=r && !isnum(s[i]))
            {
                ans+=s[i];
                i++;
            }
            if(i>r)return ans;
            string num="";
            while(i<=r && isnum(s[i]))
            {
                num+=s[i];
                i++;
            }
            int cnt=stoi(num);
            i++;
            int nl=i;
            int u=1;
            while(u)
            {
                if(s[i]=='[')u++;
                else if(s[i]==']')u--;
                i++;
            }
            int nr=i-2;
            string sans=helper(nl,nr,s);
            while(cnt--)
            {
                ans+=sans;
            }
        }
        return ans;
    }


    string decodeString(string s) {
        int n=s.size();
        string ans=helper(0,n-1,s);
        return ans;
    }
};
