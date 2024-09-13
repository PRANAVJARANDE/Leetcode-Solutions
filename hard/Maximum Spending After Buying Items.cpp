class Solution {
public:
    long long maxSpending(vector<vector<int>>& val) 
    {
            int64_t m=val.size(),n=val[0].size();
            priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> q1;
            
            for(int i=0;i<m;i++)
            {
                    q1.push({val[i][n-1],i});
            }
            
            int64_t ans=0;
            int64_t d=1;
            while(!q1.empty())
            {
                    int64_t k=q1.top().first;
                    int64_t in=q1.top().second;
                    q1.pop();
                    val[in].pop_back();
                    ans=ans+d*k;
                    d++;
                    if(val[in].size()!=0)
                    {
                            q1.push({val[in].back(),in});
                    }
                    
            }
            
            return ans;
            
            
                
            
        
    }
};
