class Solution {
public:

    vector<int> diffWaysToCompute(string s) {
        bool b=0;
        vector<int>res;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')  
            {
                b=1;
                vector<int> l=diffWaysToCompute(s.substr(0,i));
                vector<int> r=diffWaysToCompute(s.substr(i+1));
                for(auto x: l)
                {
                    for(auto y:r)
                    {
                        if(s[i]=='+')res.push_back(x+y);
                        if(s[i]=='-')res.push_back(x-y);
                        if(s[i]=='*')res.push_back(x*y);
                    }
                }
            }
        }
        if(b==0)res.push_back(stoi(s));
        return res;
    }
};
