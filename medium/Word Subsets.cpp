class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) 
    {
        int n = word1.size();
        vector<vector<int>> a(n, vector<int>(26, 0));
        vector<int> maxFreq(26, 0);  

        for(int i = 0; i < n; i++)
            for(char x : word1[i])
                a[i][x - 'a']++;

        for(auto word : word2) {
            vector<int> freq(26, 0);
            for(char x : word)
                freq[x - 'a']++;
            for(int j = 0; j < 26; j++)
                maxFreq[j] = max(maxFreq[j], freq[j]);
        }

        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            bool valid = true;
            for(int j = 0; j < 26; j++)
            {
                if(a[i][j] < maxFreq[j])
                {
                    valid = false;
                    break;
                }
            }
            if(valid) ans.push_back(word1[i]);  
        }
        return ans;
    }
};
