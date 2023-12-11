class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int n=arr.size();
        int c=n/4;
        c++;
        int k=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                k++;
            }
            else
            {
                k=1;
            }
            if(k==c)
            {
                return arr[i];
            }
        }
        return arr[0];
        
    }
};
