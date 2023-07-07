class Solution {
public:
    string getHint(string s, string g) {
        int n=s.size();
        vector<int> freq(10,0);
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==g[i])
            {
                x++;
            }
            else
            {
                freq[s[i]-'0']++;
                freq[g[i]-'0']--;
                if(freq[s[i]-'0'] <=0)
                {
                    y++;
                }
                if(freq[g[i]-'0']>=0)
                {
                    y++;
                }
            }
        }
       
        return to_string(x)+"A"+to_string(y)+"B";
    }
};
