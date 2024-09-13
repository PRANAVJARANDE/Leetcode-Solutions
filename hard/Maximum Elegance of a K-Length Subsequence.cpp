class Solution {
public:

    long long findMaximumElegance(vector<vector<int>>& arr, int k) 
    {
        long long ans=0;
        sort(arr.begin(),arr.end(),greater<vector<int>>());
        int n=arr.size(),i;
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
        for(i=0;i<k;i++)
        {
            ans+=arr[i][0];
            if(++m[arr[i][1]]>=2)
            {
                q1.push({arr[i][0],arr[i][1]});
            }
        }
        int l=m.size();
        long long tsum=(long long)l*l+ans;
        long long res=tsum;
        if(l==k)
        {
            return res;
        }
        for(int i=k;i<n;i++)
        {
            if(++m[arr[i][1]]==1)
            {
                tsum+=(long long )(arr[i][0]-q1.top().first);
                tsum+=(2*l+1);
                res=max(res,tsum);
                q1.pop();
                if(q1.empty())
                {
                    return res;
                }
            l++;
            }
            
        }
        return res;
    }
};
