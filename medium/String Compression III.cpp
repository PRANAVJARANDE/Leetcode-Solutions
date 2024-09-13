class Solution {
public:
    string compressedString(string s) {
        string ans="";
        int in=0;
        int n=s.size();

        while(in<n)
        {
            int cnt=0;
            int j=in;
            while(j<n && s[in]==s[j] && cnt<9)
            {
                j++;
                cnt++;
            }
        
            ans+=to_string(cnt)+s[in];
            in=j;
        }
        return ans;

    }
};
