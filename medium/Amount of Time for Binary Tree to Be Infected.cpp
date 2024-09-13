/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>> adj;   
    void help(TreeNode* root)
    {
        if(!root)return;
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        help(root->right);
        help(root->left);
    }

    int dfs(int in,int par)
    {
        int ans=0;
        for(int x:adj[in])
        {
            if(x!=par)
            {
                ans=max(ans,1+dfs(x,in));
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        help(root);
        int ans=dfs(start,-1);
        return ans;
    }
};
