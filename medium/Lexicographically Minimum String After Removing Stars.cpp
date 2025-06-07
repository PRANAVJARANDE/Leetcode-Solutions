class Solution {
public:
    string clearStars(string s) 
    {
        int n=s.size();
        map<char,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                for(auto &x:m)
                {
                    if(!x.second.empty())
                    {
                        x.second.pop_back();
                        break;
                    }
                }
            }
            else m[s[i]].push_back(i);
        }
        vector<int>v1;
        for(auto x:m)
        {
            for(auto y:x.second)
            {
                v1.push_back(y);
            }
        }
        sort(v1.begin(),v1.end());
        string ans(v1.size(),'0');
        for(int i=0;i<v1.size();i++)
        {
            ans[i]=s[v1[i]];
        }
        return ans;
    }
};
