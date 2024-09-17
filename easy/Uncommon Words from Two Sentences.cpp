class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        map<string,int> v1;  
        string word;
        istringstream stream1(s1);
        while(stream1>>word) 
        {
            v1[word]++;
        }
        
        istringstream stream2(s2);
        while(stream2>>word) 
        {
            v1[word]++;
        }
        vector<string> ans;
        for(auto x:v1) 
        {
            if(x.second==1)ans.push_back(x.first);
        }
        return ans;
    }
};
