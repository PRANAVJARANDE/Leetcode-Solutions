class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int the) 
    {
        int th=k*the;
        int c=0;
        int avg=0;
        for(int i=0;i<k;i++)
        {
            avg=avg+arr[i];
        }
        
            if(avg>=th)
            {
                c++;
            }
        for(int i=k;i<arr.size();i++)
        {
            avg+=arr[i];
            avg-=arr[i-k];
            if(avg>=th)
            {
                c++;
            }
        }
        return c;
    }
};
