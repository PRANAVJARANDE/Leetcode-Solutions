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

    void helper(vector<vector<int>> & ans,vector<int> &v1,TreeNode*root,int t)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL && t==root->val)
        {
            v1.push_back(root->val);
            ans.push_back(v1);
            v1.pop_back();
            return;
        }

        v1.push_back(root->val);
        helper(ans,v1,root->left,t-root->val);
        helper(ans,v1,root->right,t-root->val);
        v1.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v1;
        vector<vector<int>> ans;
        helper(ans,v1,root,targetSum);
        return ans;
    }
};
