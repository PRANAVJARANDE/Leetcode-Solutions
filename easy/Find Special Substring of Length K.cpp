class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        
        for (int i = 0; i <= n - k; i++) {
            char c = s[i];
            bool isSame = true;
            for (int j = i; j < i + k; j++) {
                if (s[j] != c) {
                    isSame = false;
                    break;
                }
            }
            
            if (!isSame) continue;
            if (i > 0 && s[i - 1] == c) continue;
            if (i + k < n && s[i + k] == c) continue;
            return 1;
        }
        return 0;
    }
};
