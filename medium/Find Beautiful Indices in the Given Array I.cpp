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
    
    vector<int> beautifulIndices(string s, string a, string b, int k) 
    {
        int n=s.size();
        int as=a.size();
        int bs=b.size();
        
        vector<int>ans,a1,a2;
        for(int i=0;i<n-as+1;i++)
        {
            string d=s.substr(i,as);
            if(d==a)
            {
                a1.push_back(i);
            }
        }
        for(int i=0;i<n-bs+1;i++)
        {
            string g=s.substr(i,bs);
            if(g==b)
            {
                a2.push_back(i);
            }
        }
        
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
