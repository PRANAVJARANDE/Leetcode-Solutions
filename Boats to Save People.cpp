class Solution {
public:
    int numRescueBoats(vector<int>& arr, int l) 
    {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int k=0;
        while(i<=j)
        {
            int c=l-arr[j];
            j--;
            if(i<=j && c>=arr[j])
            {
                j--;
            }
            else if(i<=j && c>=arr[i])
            {
                i++;
            }
            k++;
        }
        return k;
        
    }
};
