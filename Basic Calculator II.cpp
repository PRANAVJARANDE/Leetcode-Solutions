class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        vector<int>num;
        vector<char>sign;
        long long k=0;
        long long t=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' ')continue;
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                sign.push_back(s[i]);
                num.push_back(k);
                k=0;
                t=1;
            }
            else
            {
                k+=(s[i]-'0')*t;
                t*=10;
            }
        }
        num.push_back(k);
        reverse(num.begin(),num.end());
        reverse(sign.begin(),sign.end());
        

        stack<int> s1;
        s1.push(num[0]);
        char prev='+';
        for(int i=0;i<sign.size();i++)
        {
            if(sign[i]=='/')
            {
                int ta=s1.top()/num[i+1];
                s1.pop();
                s1.push(ta);
            }
            else if(sign[i]=='*')
            {
                int ta=s1.top()*num[i+1];
                s1.pop();
                s1.push(ta);
            }
            else if(sign[i]=='+')
            {
                s1.push(num[i+1]);
            }
            else
            {
                s1.push(-num[i+1]);
            }
        }

        int ans=0;
        while(!s1.empty())
        {
            ans+=s1.top();
            s1.pop();
        }
        return ans;
    }
};
