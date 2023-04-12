class Solution {
public:
    int search(vector<int>& arr, int t) 
    {
       int l=0,mid;
       int r=arr.size()-1;
       

       while(l<=r)
       {
           mid=(l+r)/2;
           
           if(arr[mid]==t)
           {
               return mid;
           }

           if(arr[mid]>=arr[l])
           {
               if(arr[mid]>=t && arr[l]<=t)
               {
                   r=mid-1;
               }
               else
               {
                   l=mid+1;
               }
           }
           else
           {
               if(arr[mid]<=t && arr[r]>=t)
               {
                   l=mid+1;
               }
               else
               {
                   r=mid-1;
               }

           }
       }

       return -1;
    }
};
