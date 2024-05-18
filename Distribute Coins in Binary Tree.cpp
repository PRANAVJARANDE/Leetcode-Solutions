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

    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }

        pair<int,int> l=helper(root->left);
        pair<int,int> r=helper(root->right);
        
        int b=l.second+r.second+root->val-1;
        int a=l.first+r.first+abs(b);
        return {a,b};
    }

    int distributeCoins(TreeNode* root) {
        pair<int,int> ans=helper(root);
        return ans.first;
    }
};
