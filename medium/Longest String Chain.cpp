class Solution {
public:
    int n;
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& arr) 
    {
        sort(arr.begin(),arr.end(),cmp);
        int ans=1;
        n=arr.size();
        unordered_map<string,int> m;
        for(int i=0;i<n;i++)
        {
            string s=arr[i];
            m[s]=1;
            for(int j=0;j<s.size();j++)
            {
                string temp=s.substr(0,j)+s.substr(j+1);
                if(m.find(temp)!=m.end())
                {
                    m[s]=max(m[s],m[temp]+1);
                    ans=max(ans,m[s]);
                }
            }
        }
        return ans;
    }
};
