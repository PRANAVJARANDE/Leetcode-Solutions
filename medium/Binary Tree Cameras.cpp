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

    map<TreeNode*,int>vis;
    int helper(TreeNode* root,TreeNode* par)
    {
        if(!root)return 0;
        int ans=helper(root->left,root)+helper(root->right,root);

        if((par==NULL && vis[root]==0) || vis[root->left]==0 || vis[root->right]==0)
        {
            ans++;
            vis[par]=1;
            vis[root]=1;
            vis[root->left]=1;
            vis[root->right]=1;
        }
        return ans;
    }

    int minCameraCover(TreeNode* root) 
    {
        vis[NULL]=1;
        return helper(root,NULL);
    }
};
