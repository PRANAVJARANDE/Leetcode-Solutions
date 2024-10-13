class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        int n=a.size();
        vector<int> ans;
        for(int i=0;i<n-k+1;i++)
        {
            map<int,int> m;
            for(int j=i;j<i+k;j++)
            {
                m[a[j]]++;
            }
            vector<vector<int>> q1;
            for(auto x: m)
            {
                q1.push_back({x.second,x.first});
            }
            sort(q1.begin(),q1.end(),greater<vector<int>>());
            int jk=0;
            for(int z=0;z<(int)min(x,(int)q1.size());z++)
            {
                jk+=(q1[z][1])*(q1[z][0]);
            }
            ans.push_back(jk);
        }
        return ans;
    }
};
