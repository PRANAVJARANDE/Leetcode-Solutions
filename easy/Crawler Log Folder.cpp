class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto x: logs)
        {
            if(x=="../")
            {
                if(ans==0)continue;
                else ans--;
            }
            else if(x=="./")
            {
                continue;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
