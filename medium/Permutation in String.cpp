class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size()>s2.size())
            return 0;

        vector<int> f1(26,0),f2(26,0);
        for(char x: s1)
            f1[x-'a']++;
        
        int k=s1.size();
        for(int i=0;i<k;i++)
        {
            f2[s2[i]-'a']++;
        }
        if(f1==f2)
        {
            return 1;
        }
        for(int i=k;i<s2.size();i++)
        {
            f2[s2[i]-'a']++;
            f2[s2[i-k]-'a']--;
            if(f1==f2)
            {
                return 1;
            }
        }
        return 0;
    }
};
