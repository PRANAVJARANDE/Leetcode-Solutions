class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        
        map<int,int> m;
        for(int x: arr)
        {
            m[x]++;
        }

        vector<int> v1;
        for(auto x: m)
        {
            v1.push_back(x.second);
        }
        sort(v1.begin(),v1.end());
        int n=v1.size();
        for(int i=0;i<n;i++)
        {
            k-=v1[i];
            if(k<0)
            {
                return n-i;
            }
        }
        return 0;
    }
};
