class Solution {
  public:
    void nearlySorted(vector<int>& a, int k) 
    {
        int n=a.size();
        multiset<int>s1;
        for(int i=0;i<k;i++)s1.insert(a[i]);
        for(int i=0;i<n;i++)
        {
            if(i+k<n)s1.insert(a[i+k]);
            a[i]=(*s1.begin());
            s1.erase(s1.find(a[i]));
        }
    }
};
