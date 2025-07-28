
class Solution {
  public:
    bool closestSimilarElements(int n, vector<int> &a, int idiff,int vdiff) 
    {
        
        multiset<int>s1;
        for(int i=0;i<n;i++)
        {
            if(i-idiff-1>=0)s1.erase(s1.find(a[i-idiff-1]));
            int l=a[i]-vdiff;
            int r=a[i]+vdiff;
            auto it1=s1.lower_bound(l);
            auto it2=s1.upper_bound(r);
            if(it1!=it2)return 1;
            s1.insert(a[i]);   
        }
        return 0;
    }
};
