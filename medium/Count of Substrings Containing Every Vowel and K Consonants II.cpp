class Solution {
public:

    bool isvovel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return 1;
        return 0;
    }

    long long countOfSubstrings(string s, int k) {
        int n=s.size();
        long long ans=0;
        int cons=0;
        int l=0;
        map<char,int> m;
        vector<int> nx(n);
        int pos=n;
        for(int i=n-1;i>=0;i--)
        {
            nx[i]=pos;
            if(!isvovel(s[i]))pos=i;
        }

        for(int i=0;i<n;i++)
        {
            if(isvovel(s[i]))m[s[i]]++;
            else cons++;
            
            while(cons>k)
            {
                if(isvovel(s[l]))
                {
                    m[s[l]]--;
                    if(m[s[l]]==0)m.erase(m[s[l]]);
                }
                else
                {
                    cons--;
                }
                l++;
            }
            while(m.size()==5 && k==cons)
            {
                ans+=(nx[i]-i);
                if(isvovel(s[l]))
                {
                    m[s[l]]--;
                    if(m[s[l]]==0)m.erase(m[s[l]]);
                }
                else
                {
                    cons--;
                }
                l++;
            }
        }
        return ans;
    }
};
