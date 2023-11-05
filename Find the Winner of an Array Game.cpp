class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        if(k==1)    
            return max(arr[0],arr[1]);
        
        int maxi=INT_MIN;
        for(int x: arr)
            maxi=max(maxi,x);

        if(k>=arr.size())
            return maxi;

        int c=0;
        int curr=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(curr>arr[i])
                c++;
            else
            {
                c=1;
                curr=arr[i];
            }

            if(c==k)
                return curr;
        }
        return curr;
    }
};
