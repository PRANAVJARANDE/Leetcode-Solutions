class Solution {
public:
        
        bool gd(string a,string b)
        {
               int h1=(a[0]-'0')*10 + a[1]-'0';
               int h2=(b[0]-'0')*10 + b[1]-'0';
                
                if(h1==h2)
                {
                        return 1;
                }
                if(abs(h1-h2)>=2)
                {
                        return 0;
                }
                int ma=(a[2]-'0')*10 + a[3]-'0';
                int mb=(b[2]-'0')*10 + b[3]-'0';
                
                int diff=mb+60-ma;
                if(diff<60)
                {
                        return 1;
                }
                return 0;
        }
         
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) 
    {
            unordered_map<string,vector<string>> m;
            for(auto x: arr)
            {
                    m[x[0]].push_back(x[1]);
            }
        
            vector<string> ans;
            for(auto x: m)
            {
                    string name=x.first;
                    vector<string> v1=x.second;
                    if(v1.size()<3)
                    {
                            continue;
                    }
                    sort(v1.begin(),v1.end());
                    for(int i=2;i<v1.size();i++)
                    {
                        if(gd(v1[i-2],v1[i]))
                        {
                                ans.push_back(name);
                                break;
                        }
                    }
            }
            return ans;
    }
};
