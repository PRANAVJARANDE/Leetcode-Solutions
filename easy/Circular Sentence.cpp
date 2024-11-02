class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v1;
        stringstream ss(sentence);
        string word;
        while (ss >> word) 
        {
            v1.push_back(word);
        }
        int sz=v1.size();
        for(int i=0;i<sz;i++)
        {
            if(v1[i][v1[i].size()-1]!=v1[(i+1)%sz][0])
            {
                return 0;
            }
        }
        return 1;
    }
};
