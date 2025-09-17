class Solution {
  public:
    string decodedString(string &s) 
    {
        int n=s.size();
        stack<int>s1;
        stack<string>s2;
        s1.push(1);
        s2.push("");
        
        for(int i=0;i<n;i++)
        {
            if('0'<=s[i] && s[i]<='9')
            {
                int num=0;
                while('0'<=s[i] && s[i]<='9')
                {
                    num=num*10+(s[i]-'0');
                    i++;
                }
                s1.push(num);
                s2.push("");
            }
            else if(s[i]==']')
            {
                string res="";
                int cnt=s1.top();
                string ta=s2.top();
                s1.pop();
                s2.pop();
                while(cnt--)
                {
                    res+=ta;
                }
                string ntp=s2.top();
                ntp+=res;
                s2.pop();
                s2.push(ntp);
            }
            else
            {
                string ntp=s2.top();
                ntp+=s[i];
                s2.pop();
                s2.push(ntp);
            }
        }
        return s2.top();
        
    }
};
