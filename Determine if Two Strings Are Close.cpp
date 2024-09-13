class Solution {
public:
    bool closeStrings(string s1, string s2) 
    {
        if(s1.size()!=s2.size())
            return 0;
        
        int n=s1.size();
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<n;i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if((v1[i]==0 && v2[i]!=0) || (v1[i]!=0 && v2[i]==0))
            {
                return 0;
            }
        }

        multiset<int>a,b;
        for(int i=0;i<26;i++)
        {
            if(v1[i]!=0)
            {
                a.insert(v1[i]);
            }
            if(v2[i]!=0)
            {
                b.insert(v2[i]);
            }
        }
        return a==b;
    }
};
