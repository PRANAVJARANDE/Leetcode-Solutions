/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int n;
    map<Node*,int>m;
    void helper(Node* root)
    {
        if(!root)return;
        m[root]=n++;
        helper(root->left);
        helper(root->right);
    }
    
    
    void make_adj_list(Node* root,vector<vector<int>>&adj,vector<int>&nums)
    {
        nums[m[root]]=root->data;
        if(root->left)
        {
            adj[m[root]].push_back(m[root->left]);
            adj[m[root->left]].push_back(m[root]);
            make_adj_list(root->left,adj,nums);
        }
        if(root->right)
        {
            adj[m[root]].push_back(m[root->right]);
            adj[m[root->right]].push_back(m[root]);
            make_adj_list(root->right,adj,nums);
        }
    }
  
    int distCandy(Node* root) 
    {
        n=0;
        helper(root);
        vector<vector<int>>adj(n);
        vector<int>nums(n,0);
        make_adj_list(root,adj,nums);
        
        vector<int>deg(n,0);
        queue<int>q1;
        vector<int>gt=nums;
        vector<int>nd(n,1);
        
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            deg[i]=adj[i].size();
            if(deg[i]==1)q1.push(i);
        }
        
        int ans=0;
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            if(vis[in])continue;
            vis[in]=1;
            ans+=abs(gt[in]-nd[in]);
            // cout<<in<<" "<<gt[in]<<" "<<nd[in]<<endl;
            for(auto x:adj[in])
            {
                if(vis[x]==0)
                {
                    deg[x]--;
                    gt[x]+=max(0,gt[in]-nd[in]);
                    nd[x]+=max(0,nd[in]-gt[in]);
                    if(deg[x]==1)
                    {
                        q1.push(x);
                    }
                }
            }
        }
        return ans;
    }
};
