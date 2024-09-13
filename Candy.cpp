class Solution {
public:

    void checkk(vector<int> &cand,int i,vector<int> arr)
    {
        if(i==1)
        {
            return;
        }
        if(arr[i-1]>arr[i])
        {

        if(cand[i-1]<=cand[i])
        {
            cand[i-1]=cand[i]+1;
        }
        
        checkk(cand,i-1,arr);
        


        }
    }

    int candy(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> cand(n,1);

        if(arr.size()==0)
        {
            return 0;
        }
        if(arr.size()==1)
        {
            return 1;
        }

        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]>arr[i])
            {
                cand[i+1]=cand[i]+1;
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1] < arr[i])
            {
                if(cand[i+1] >= cand[i])
                {
                    cand[i]=cand[i+1]+1;
                }
            }
        }

        int ans=0;
        for(int x: cand)
        {
            ans=ans+x;
        }
        return ans;


        
    }
};
