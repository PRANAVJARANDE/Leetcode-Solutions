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

    void helper(TreeNode* root,int b,int l,int &ans)
    {
        if(root==NULL)
            return;

        ans=max(ans,l);
        if(b==1)
        {
            helper(root->left,0,l+1,ans);
            helper(root->right,1,1,ans);
        }
        else
        {
            helper(root->right,1,l+1,ans);
            helper(root->left,0,1,ans);
        }
    }


    int longestZigZag(TreeNode* root) 
    {
        int ans=0;
        helper(root,0,0,ans);
        helper(root,1,0,ans);
        return ans;
    }
};
