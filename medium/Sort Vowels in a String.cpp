class Solution {
public:

    bool isvov(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            return 1;
        }
        return 0;
    }

    string sortVowels(string s) 
    {
        map<char,int> m;
        for(char x: s)
            if(isvov(x))m[x]++;
        
        int in=0;
        for(int i=0;i<s.size();i++)
        {
            if(isvov(s[i]))
            {
                auto it=m.begin();
                s[i]=it->first;
                if(--it->second==0)
                {
                    m.erase(it);
                }
            }
        }
        return s;
    }
};
