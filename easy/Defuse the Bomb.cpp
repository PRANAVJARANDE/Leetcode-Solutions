class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        int n=a.size();
        vector<int> psum(n,0);
        if(k==0)return psum;
        else if(k>0)
        {
            int s=0;
            int in=(k+1)%n;
            for(int i=0;i<=k;i++)s+=a[i];
            for(int i=0;i<n;i++)
            {
                s-=a[i];
                psum[i]=s;
                s+=a[in];
                in++;
                in=in%n;
            }
            return psum;
        }
        else
        {
            k=-k;
            int s=0;
            int in=n-k;
            for(int i=in;i<n;i++)s+=a[i];
            for(int i=0;i<n;i++)
            {
                psum[i]=s;
                s-=a[in];
                s+=a[i];
                in++;
                in=in%n;
            }
            return psum;
        }


    }
};
