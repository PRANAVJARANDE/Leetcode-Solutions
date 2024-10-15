class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        long long oc=0;
        for(int x:s)
        {
            if(x=='1')oc++;
            else
            {
                ans+=oc;
            }
        }
        return ans;
    }
};
