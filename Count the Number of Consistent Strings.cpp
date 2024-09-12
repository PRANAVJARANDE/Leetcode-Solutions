class Solution {
public:
    int countConsistentStrings(string a, vector<string>& words) {
        map<char,bool> m;
        for(char x:a)
        {
            m[x]=1;
        }
        int ans=0;
        for(auto x: words)
        {
            bool b=0;
            for(char f:x)
            {
                if(m[f]==0)
                {
                    b=1;
                }
            }
            if(b==0)ans++;
        }
        return ans;
    }
};
