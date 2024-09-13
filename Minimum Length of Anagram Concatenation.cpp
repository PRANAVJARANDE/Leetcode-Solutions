class Solution {
public:
    
    int n;
    bool checker(string &s,int k)
    {
        vector<int> f1(26,0);
        for(int i=0;i<k;i++)
        {
            f1[s[i]-'a']++;
        }
        
        for(int i=k;i<n;i+=k)
        {
            vector<int> f2(26,0);
            for(int j=i;j<i+k;j++)
            {
                f2[s[j]-'a']++;
            }
            if(f1!=f2)return 0;
        }
        return 1;
    }
    
    
    int minAnagramLength(string s) 
    {
        n=s.size();
        map<char,int> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                int op1=i;
                int op2=n/i;
                if(checker(s,op1))ans=min(ans,op1);
                if(checker(s,op2))ans=min(ans,op2);
            }
        }
        
        return ans;
        
    }
};
