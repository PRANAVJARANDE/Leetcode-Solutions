class Solution {
public:
    int minDeletions(string s) 
    {
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
            m[s[i]]++;
        int ans=0;
        unordered_map<int,int> freq;
        for(auto x: m)
        {
            if(freq.find(x.second)==freq.end())
            {
                freq[x.second]++;
            }
            else
            {
                int j=x.second;
                while(freq.find(j)!=freq.end())
                {
                    j--;
                    ans++;
                }
                if(j>0)
                {
                    freq[j]++;
                }
            }
        }
        
        return ans;
    }
};
