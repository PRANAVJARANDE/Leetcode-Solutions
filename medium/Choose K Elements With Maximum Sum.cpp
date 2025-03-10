class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n=nums1.size();
        vector<vector<int>>v1(n,vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=nums1[i];
            v1[i][1]=nums2[i];
            v1[i][2]=i;
        }
        sort(v1.begin(),v1.end());
        vector<long long>ans(n,0);
        priority_queue<long long,vector<long long>,greater<long long>>q1;
        long long res=0;
    
        for(int i=0;i<n;i++)
        {
            if(i-1>=0 && v1[i-1][0]==v1[i][0])ans[v1[i][2]]=ans[v1[i-1][2]];
            else ans[v1[i][2]]=res;
            
            res+=v1[i][1];
            q1.push(v1[i][1]);
            if(q1.size()>k)
            {
                res-=q1.top();
                q1.pop();
            }
        }
        return ans;
        
            
            
    }
};
