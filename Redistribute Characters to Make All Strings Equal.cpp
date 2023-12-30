class Solution {
public:
    bool makeEqual(vector<string>& arr) 
    {
        unordered_map<char,int> m;
        for(string x: arr)
        {
            for(char ch: x)
            {
                m[ch]++;
            }
        }

        int n=arr.size();
        for(auto x: m)
        {
            if(x.second%n!=0)
                return 0;
        }
        return 1;
        
    }
};
