class Solution {
public:
    bool isnum(char c)
    {
        return '0'<=c && c<='9';
    }

    string countOfAtoms(string s) 
    {
        int n=s.size();
        stack<int>s1;
        int pv=1;

        map<string,int>mp;
        int prod=1;

        for(int i=n-1;i>=0;)
        {
            if(isnum(s[i]))
            {
                string num="";
                while(i>=0 && isnum(s[i]))
                {
                    num=s[i]+num;
                    i--;
                }
                int val=stoi(num);
                if(i>=0 && s[i]==')')
                {
                    s1.push(val);
                    prod*=val;
                    i--;
                }
                else pv=val;
            }
            else if(s[i]=='(')
            {
                if(!s1.empty())
                {
                    prod=prod/s1.top();
                    s1.pop();
                }
                i--;
            }
            else if(s[i]==')') 
            {
                s1.push(1);
                i--;
            }
            else 
            {
                string ele;
                while(i>=0) 
                {
                    ele.push_back(s[i]);
                    if ('A'<=s[i] && s[i]<='Z') 
                    {
                        i--;
                        break;
                    }
                    i--;
                }
                reverse(ele.begin(),ele.end());
                mp[ele]+=prod*pv;
                pv=1;
            }
        }

        string ans="";
        for (auto &x : mp) 
        {
            ans+=x.first;
            if(x.second>1)ans+=to_string(x.second);
        }
        return ans;
    }
};
