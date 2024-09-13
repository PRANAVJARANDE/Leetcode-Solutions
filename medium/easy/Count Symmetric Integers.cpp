class Solution {
public:
        
        bool issym(int k)
        {
                string s=to_string(k);
                int n=s.size();
                if(n%2==1)
                        return 0;
                
                int ans=0;
                for(int i=0;i<n/2;i++)
                {
                        ans+=s[i];
                        ans-=s[n-i-1];
                }
                return ans==0;
        }
        
        
        
    int countSymmetricIntegers(int low, int high) 
    {
            int k=0;
           for(int i=low;i<=high;i++)
           {
                if(issym(i))
                {
                        k++;
                }
           }
            return k;
        
    }
};
