class Solution {
public:
    int alternatingSubarray(vector<int>& arr) 
    {
        int l=0;
        int n=arr.size();
        int ans=-1;
        int fans=-1;
        
        while(l<n-1)
        {
            if(arr[l]-arr[l+1]==-1)
            {
                ans=2;
                while(l+2<n && arr[l]==arr[l+2])
                {
                    ans++;
                    l++;
                }
                fans=max(fans,ans);
            }
            l++;
        }
        return fans;
    }
};
