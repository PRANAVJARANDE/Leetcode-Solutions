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

    int helper(TreeNode* root,int *s)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ls=0,rs=0;
        int a=helper(root->left,&ls);
        int b=helper(root->right,&rs);
        *s=ls+rs+root->val;
        return abs(ls-rs)+a+b;
    }


    int findTilt(TreeNode* root) {
        int s=0;
        return helper(root,&s);
    }
};
