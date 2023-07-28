class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> freq(26,0),ref(26,0);
        vector<int> ans;
        
        int n=s.size();
        int l1=p.size();
        if(n<l1)
        {
            return ans;
        }
        for(int i=0;i<l1;i++)
        {
            freq[s[i]-'a']++;
            ref[p[i]-'a']++;
        }
        if(ref==freq)
        {
            ans.push_back(0);
        }
        for(int i=l1;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            freq[s[i-l1]-'a']--;
            if(freq==ref)
            {
                ans.push_back(i-l1+1);
            }
        }
        return ans;
    }
};
