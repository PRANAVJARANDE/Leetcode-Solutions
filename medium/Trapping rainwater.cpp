class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int wa=0,dw=0;
        int r=arr.size()-1;
        int lmax=arr[0];
        int rmax=arr[r];

        for(int i=0;i<arr.size();i++)
        {
            lmax=max(lmax,arr[i]);
            wa+=(lmax-arr[i]);
        }

        while(1)
        {
            rmax=max(rmax,arr[r]);
            if(lmax==rmax)
            {
                break;
            }
            dw=dw+(lmax-rmax);
            r--;
        }
        int g=wa-dw;
        
        return g;

    }
};
