class Solution {
public:
    vector<string> buildArray(vector<int>& tar, int n) 
    {
        int i=0,j=1;
        vector<string> ans;
        while(i<tar.size() && j<=n)
        {
            while(tar[i]!=j)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            }
            ans.push_back("Push");
            i++; 
            j++; 
        }
        return ans;
        
    }
};
