class Solution {
public:
    int maxFreq(string s, int ml, int mi, int ma) 
    {
        unordered_map<string,int> m;
        unordered_map<char,int> freq;
        int l=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            while(freq.size()>ml || i-l+1>mi)
            {
                freq[s[l]]--;
                if(freq[s[l]]==0)
                {
                    freq.erase(s[l]);
                }
                l++;
            }
            if(i-l+1>=mi && i-l+1 <= ma && freq.size()<=ml)
            {
                ans=max(ans,++m[s.substr(l,mi)]);
            }
        }
        return ans;
    }
};
