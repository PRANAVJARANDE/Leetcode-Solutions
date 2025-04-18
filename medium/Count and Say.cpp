class Solution {
public:
    string countAndSay(int n) 
    {
        n--;
        string r="1";
        while(n>0)
        {
            int sz=r.size();
            string s="";
            int in=sz-1;
            while(in>=0)
            {
                char ch=r[in];
                int cnt=0;
                while(in>=0 && r[in]==ch)
                {
                    cnt++;
                    in--;
                }
                s=to_string(cnt)+ch+s;
            }
            r=s;
            n--;
        }
        return r;
    }
};
