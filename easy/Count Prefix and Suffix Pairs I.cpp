class Solution {
public:

    bool check(string a,string b)
    {
        int n=a.size(),m=b.size();
        if(n>m)return 0;
        if(b.substr(0,n)==a && b.substr(m-n)==a)return 1;
        return 0;
    }


    int countPrefixSuffixPairs(vector<string>& a) {
        int ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(a[i],a[j]))
                {
                    cout<<a[i]<<" "<<a[j]<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};
