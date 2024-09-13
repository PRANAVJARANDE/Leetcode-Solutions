class Solution {
public:

    bool ispali(string s)
    {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                return 0;
            }
        }
        return 1;
    }

    vector<vector<string>>ans;
    void helper(string s,vector<string>&v1)
    {
        if(s.size()==0)
        {
            vector<string>temp=v1;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(ispali(s.substr(i)))
            {
                v1.push_back(s.substr(i));
                helper(s.substr(0,i),v1);
                v1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string>v1;
        helper(s,v1);
        return ans;
    }
};
