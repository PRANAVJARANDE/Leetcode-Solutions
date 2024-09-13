class Solution {
public:

    void helper(vector<int> &cookies,vector<int>temp,int k,int ind,int &ans)
    {
        if(ind==cookies.size())
        {
            ans=min(ans,*max_element(temp.begin(),temp.end()));
            return ;
        }

        for(int i=0;i<k;i++)
        {
            if(i>0 && temp[i]==temp[i-1])
            {
                continue;
            }
            if(temp[i]+cookies[ind]>ans)
            {
                continue;
            }
            temp[i]+=cookies[ind];
            helper(cookies,temp,k,ind+1,ans);
            temp[i]-=cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) 
    {
        if(k==0)
        {
            return 0;
        }
        
        int ans=INT_MAX;
        vector<int> temp(k,0);
        helper(cookies,temp,k,0,ans);
        return ans;
    }
};
