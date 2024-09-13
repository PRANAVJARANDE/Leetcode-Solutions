class Solution {
public:
    int countTriplets(vector<int>& a) 
    {
        map<int,vector<int>> m;
        m[0].push_back(-1);
        int x=0;
        int ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            x=x^a[i];
            for(int x:m[x])
            {
                ans+=i-x-1;
            }
            m[x].push_back(i);           
        }
        return ans;
    }
};
