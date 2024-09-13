class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> s1,s2;
        for(int x: nums1)s1.insert(x);
        for(int x: nums2)s2.insert(x);
        int n=nums1.size();
        int k=0,c=0;
        for(auto x: s1)
        {
            if(s2.find(x)==s2.end())
            {
                k++;
            }
            else
            {
                c++;
            }
        }
        int u1=k,u2=(s2.size()-c);
        int ans=min(n/2,u1)+min(n/2,u2)+c;
        return min(n,ans);
        
    }
};
