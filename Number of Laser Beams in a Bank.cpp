class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int n=bank.size();
        int ans=0;
        int pv=0;
        for(int i=0;i<n;i++)
        {
            int k=0;
            for(char x: bank[i])
            {
                if(x=='1')
                {
                    k++;
                }
            }
            if(k==0)
            {
                continue;
            }
            ans+=pv*k;
            pv=k;
        }
        return ans;
    }
};
