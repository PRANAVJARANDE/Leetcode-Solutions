class Solution {
public:

    int maxLength(vector<string>& arr) 
    {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<pow(2,n);i++)
        {
            int sz=0;
            vector<int> curr(26,0);
            bool b=0;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    sz+=arr[j].size();
                    for(char x: arr[j])
                    {
                        curr[x-'a']++;
                        if(curr[x-'a']>1)
                        {
                            sz=0;
                            b=1;
                            break;
                        }
                    }
                }
                if(b==1)
                {
                    break;
                }
            }
            ans=max(ans,sz);
        }
        return ans;
    }
};
