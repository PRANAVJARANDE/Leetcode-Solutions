class Solution {
public:
    
    char check(char c)
    {
        int v=c-'a';
        int nv=25-v;
        char ch=nv+'a';
        return ch;
    }
    
    long long calculateScore(string s) {
        map<char,vector<int>>m;
        int n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            char mr=check(s[i]);
            if(!m[mr].empty())
            {
                ans+=i-m[mr].back();
                m[mr].pop_back();
            }
            else
            {
                m[s[i]].push_back(i);
            }
        }
        return ans;
        
        
        
    }
};
