class Solution {
public:
    
    
    bool check(map<char,int>& m, int k) {
        string vowels = "aeiou";
        for (char v : vowels) {
            if (m[v] == 0) {
                return false;
            }
        }
        int consonants = 0;
        for (auto& [ch, count] : m) {
            if (vowels.find(ch) == string::npos) {
                consonants += count;
            }
        }
        return consonants == k;
    }
    
    int countOfSubstrings(string s, int k) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            map<char,int> m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                if(check(m,k))ans++;
            }
        }
        return ans;
        
    }
};
