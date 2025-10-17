class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) 
    {
        map<int,int>m;
        for(auto &x:nums)m[((x%v)+v)%v]++;
        
        map<int,int>m1;
        for(auto x:m)
        {   
            //cout<<x.first<<" "<<x.second<<endl;
            int cv=0;
            int z=x.second;
            while(z--)
            {
                m1[x.first+cv]=1;
                cv+=v;
            }
        }
        int mx=0;
        for(auto x:m1)
        {
            //cout<<x.first<<endl;
            if(x.first==mx)mx++;
            else return mx;
        }
        return nums.size();
    }
};
