class Solution {
public:
    
    bool match(const vector<int>& m1, const vector<int>& m2) {
        for (int i = 0; i < 26; i++) {
            if (m1[i] < m2[i]) return false;
        }
        return true;
    }

    long long validSubstringCount(string s, string w2) {
        vector<int> m2(26, 0), m1(26, 0); 
        for (char x : w2) m2[x - 'a']++;
        int n = s.size();
        int l = 0;
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            m1[s[i] - 'a']++;
            
            while (match(m1, m2)) {
                ans += n - i; 
                m1[s[l] - 'a']--; 
                l++;
            }
        }
        
        return ans;
    }
};
