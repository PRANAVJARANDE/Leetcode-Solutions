class Solution {
public:
    
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>psum(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')psum[i+1]=1+psum[i];
            else psum[i+1]=psum[i];
        }
        int ans=0;
        for(int i=0;i*i<=n;i++)
        {
            int req=i*i;
            int l=0,r=0;  
            for(int j=0;j<n;j++)
            {
                l=max(l,j);
                r=max(r,l);
                while(l<n && (psum[l+1]-psum[j])<i)
                {
                    l++;
                }
                if(l==n)break;
                while(r<n && (psum[r+1]-psum[j])<=i)
                {
                    r++;
                }
                int one=(r-j)-(psum[r]-psum[j]);
                if(one>=req)ans+=min(one-req+1,r-l);
            }   
        }
        return ans;
    }
};
