class Solution {
public:

    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }

    vector<int> topStudents(vector<string>& p, vector<string>& n, vector<string>& r, vector<int>& id, int k) 
    {
        unordered_set<string> s1(p.begin(),p.end()),s2(n.begin(),n.end());
        vector<pair<int,int>> q1;
        for(int j=0;j<r.size();j++)
        {
            int point=0;
            string word;
            istringstream ss(r[j]);
            while(ss>>word)
            {
                if(s1.find(word)!=s1.end())
                {
                    point+=3;
                }
                else if(s2.find(word)!=s2.end())
                {
                    point-=1;
                }
            }
            q1.push_back({point,id[j]});
        }
            sort(q1.begin(),q1.end(),cmp);
            vector<int> ans;
            for(int i=0;i<k;i++ )
            {
                ans.push_back(q1[i].second);
            }
            return ans;
    }
};
