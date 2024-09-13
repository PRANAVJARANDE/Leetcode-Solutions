class Solution {
public:
    
    bool bsea(vector<int>&a2,int mini,int maxi)
    {
        int i=0,j=a2.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(a2[mid]<=maxi && a2[mid]>=mini)
            {
                return 1;
            }
            
            if(a2[mid]>maxi)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return 0;
    }

    vector<int> prefix_function(string s)
    {
        int n=s.size();
        vector<int> pi(n,0);
        for(int i=1;i<n;i++)
        {
            int j=pi[i-1];
            while(j>0 && s[i]!=s[j])
            {
                j=pi[j-1];
            }

            if(s[i]==s[j])
            {
                j++;
            }
            pi[i]=j;
        }
        return pi;
    }

    vector<int> kmp(string t,string s)
    {
        vector<int> res=prefix_function(s);
        vector<int> ans;
        int pos=-1;
        int i=0,j=0;
        while(i<t.size())
        {
            if(t[i]==s[j])
            {
                i++;
                j++;
            }

            if(j==s.size())
            {
                ans.push_back(i-j); 
                j=res[j-1];
            }
            else if(i<t.size() && t[i]!=s[j])
            {
                if(j!=0) j=res[j-1];
                else i++;
            }
        }
        return ans;
    }


    
    vector<int> beautifulIndices(string s, string a, string b, int k) 
    {
        int n=s.size();
        vector<int>ans;
        vector<int> a1=kmp(s,a);
        vector<int> a2=kmp(s,b);
        
        for(int x: a1)
        {
            if(bsea(a2,x-k,x+k))
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
