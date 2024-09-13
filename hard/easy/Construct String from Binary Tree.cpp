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

    void helper(TreeNode* root,string &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans=ans+to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        if(root->left==NULL)
        {
            ans=ans+"()";
        }
        else
        {
            ans=ans+"(";
            helper(root->left,ans);
            ans=ans+")";
        }
       
        if(root->right==NULL)
        {
            return;
        }
        else
        {
            ans=ans+"(";
            helper(root->right,ans);
            ans=ans+")";
        }
    }

    string tree2str(TreeNode* root) {
        string ans="";
        helper(root,ans);
        return ans;
    }
};
