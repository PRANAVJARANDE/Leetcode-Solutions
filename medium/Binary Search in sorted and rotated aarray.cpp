class Solution 
{
public:
    bool search(vector<int>& arr, int t) 
    {
        int l=0;
        int r=arr.size()-1;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==t)
            {
                return 1;
            }

            if(arr[l]==arr[mid] && arr[mid]==arr[r])
            {
                r--;
                l++;
            }
            
            else if(arr[l]>arr[mid])
            {
                if(t>arr[mid] && t<=arr[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }

            }
            else if(arr[l]<=arr[mid])
            {
                if(t<arr[mid] && t>=arr[l])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
           
        }

        return 0;
    }
};
