class Solution {
public:
    int finalValueAfterOperations(vector<string>& a) 
    {
        int ans=0;
        for(auto x:a)
        {
            if(x[0]=='-' || x[2]=='-')ans--;
            else ans++;
        }
        return ans;
    }
};
