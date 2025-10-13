class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) 
    {
        vector<string>ans;
        vector<int>freq(26,0);
        for(int i=0;i<a.size();i++)
        {
            if(i==0)
            {
                for(auto x:a[i])freq[x-'a']++;
                ans.push_back(a[0]);
            }
            else
            {
                vector<int>freq1(26,0);
                for(auto x:a[i])freq1[x-'a']++;
                if(freq1==freq)continue;
                ans.push_back(a[i]);
                freq=freq1;
            }
        }
        return ans;
    }
};
