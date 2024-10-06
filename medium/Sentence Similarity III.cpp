class Solution {
public:

    vector<string> helper(const string&s) 
    {
        vector<string> v1; 
        istringstream iss(s); 
        string word;
        while(iss>>word)
        {
            v1.push_back(word);
        }
        return v1; 
    }

    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1=helper(s1);
        vector<string> v2=helper(s2);
        if(v1.size()<v2.size())swap(v1,v2);
        int n=v1.size(),m=v2.size();
        int l=0;
        while(l<n && l<m && v1[l]==v2[l])
        {
            l++;
        }
        int r1=n-1,r2=m-1;
        while(r1>=0 && r2>=0 && v1[r1]==v2[r2])
        {
            r1--;
            r2--;
        }
        if(r2<l)return 1;
        return 0;
    }
};
