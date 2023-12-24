class Solution {
public:


int findMaxCommonElement(vector<int>& v1, vector<int>& v2) 
{
    unordered_set<int> set1(v1.begin(), v1.end());
    int maxCommonElement = -1;
    
    for (int num : v2) 
    {
        if (set1.count(num) > 0) 
        {
            maxCommonElement = max(maxCommonElement, num);
        }
    }
    return maxCommonElement;
}
    
    
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) 
    {
        hf.push_back(1);
        hf.push_back(m);
        vf.push_back(1);
        vf.push_back(n);
        
        
        vector<int> v1,v2;
        for(int i=0;i<hf.size();i++)
        {
            for(int j=i+1;j<hf.size();j++)
            {
                v1.push_back(abs(hf[i]-hf[j]));
            }
        }
        
        
        for(int i=0;i<vf.size();i++)
        {
            for(int j=i+1;j<vf.size();j++)
            {
                v2.push_back(abs(vf[i]-vf[j]));
                
            }
        }
        
        
        long long ans=findMaxCommonElement(v1,v2);
        if(ans==-1)
        {
            return -1;
        }
        
        long long mod=1e9+7;
        long long a=(ans*ans)%mod;
        return a;
    }
};
