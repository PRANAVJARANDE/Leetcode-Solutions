class Solution {
public:
    vector<string> removeSubfolders(vector<string>& a) {
        sort(a.begin(),a.end());
        map<string,int> m;
        for(auto x: a)
        {
            bool b=0;
            for(int i=0;i<x.size();i++)
            {
                while(i<x.size() && x[i]!='/')i++;
                string res=x.substr(0,i);
                if(m[res])
                {
                    b=1;
                }
            }
            if(b==0)m[x]++;
        }
        vector<string> ans;
        for(auto x:m)
        {
            if(x.second)ans.push_back(x.first);
        }
        return ans;
    }
};
