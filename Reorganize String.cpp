class Solution {
public:
    string reorganizeString(string s) 
    {
        vector<pair<int,char>> freq(26);
        for(int i=0;i<26;i++)
        {
            freq[i].first=0;
            freq[i].second='a'+i;
        } 
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a'].first++;
        }
        sort(freq.begin(),freq.end(),greater<pair<int,char>>());

        string h="";
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq[i].first;j++)
            {
                h+=freq[i].second;
            }
        }

        string ans(n,'0');
        int in=0;
        for(int i=0;i<n;i=i+2)
        {
            ans[i]=h[in++];
        }
        for(int i=1;i<n;i+=2)
        {
            ans[i]=h[in++];
        }
        for(int i=0;i<n-1;i++)
        {
            if(ans[i]==ans[i+1])
            {
                return "";
            }
        }
        return ans;
    }
};
