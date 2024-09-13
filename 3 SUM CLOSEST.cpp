class Solution {
public:
    int threeSumClosest(vector<int>& arr, int t) 
    {
        sort(arr.begin(),arr.end());
        int m;
        
        int dist=INT_MAX;
        int ans;
        for(int i=0;i<arr.size()-2;i++)
        {
            int tn=t-arr[i];
            int l=i+1;
            int r=arr.size()-1;
            int s;
            while(l<r)
            {
                s=arr[l]+arr[r];
                if(arr[l]+arr[r]==tn)
                {
                    return t;
                }
                else if(arr[l]+arr[r]<tn)
                {
                    l++;
                }
                else
                {
                    r--;
                }


            if(dist>abs(t-(s+arr[i])))
            {
                dist=abs(t-(s+arr[i]));
                ans=s+arr[i];
            }
            }
            
           
        }
        return ans;
    }
};
