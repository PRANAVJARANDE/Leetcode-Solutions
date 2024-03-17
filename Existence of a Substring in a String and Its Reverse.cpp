class Solution {
public:
    bool isSubstringPresent(string s) 
    {
        int n=s.size();
        map<string,int> m;
        for(int i=0;i<n-1;i++)
        {
            string a1=to_string(s[i])+to_string(s[i+1]);
            string a2=to_string(s[i+1])+to_string(s[i]);
            m[a1]++;
            if(m.find(a2)!=m.end())return 1;
        }
        return 0;
        
    }
};
