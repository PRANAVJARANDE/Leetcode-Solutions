class Solution {
public:

    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) 
    {
        int n=nums.size();
        sort(q.begin(),q.end());  

        for(auto x:q)
        {
            cout<<x[0]<<" "<<x[1]<<endl;
        }

        int in=0;
        priority_queue<int>q1;
        vector<int>psum(n+1,0);
        int cs=0;
        for(int i=0;i<n;i++)
        {
            while(in<q.size() && q[in][0]<=i)
            {
                q1.push(q[in][1]);
                in++;
            }
            cs+=psum[i];
            while(cs<nums[i] && !q1.empty() && q1.top()>=i)
            {
                cs++;
                psum[(int)q1.top()+1]--;
                q1.pop();
            }
            if(cs<nums[i])return -1;
        }

        int ans=q1.size();
        return ans;
        
    }
};
