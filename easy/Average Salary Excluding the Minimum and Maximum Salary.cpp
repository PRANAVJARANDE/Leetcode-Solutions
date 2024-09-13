class Solution {
public:
    double average(vector<int>& arr) 
    {
        int ma=INT_MIN,mi=INT_MAX,s=0;
        for(int i=0;i<arr.size();i++)
        {
            ma=max(ma,arr[i]);
            mi=min(mi,arr[i]);
            s=s+arr[i];
        }    
        s=s-(ma+mi);
        double ans=s/(arr.size()-2.0);
        return ans;
    }
};
