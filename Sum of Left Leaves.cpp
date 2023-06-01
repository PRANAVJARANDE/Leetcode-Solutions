class Solution {
public:
    void helper(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left !=NULL && root->left->right==NULL && root->left->left==NULL)
        {
            ans=ans+root->left->val;
        }
        helper(root->left,ans);
        helper(root->right,ans);
    }


    int sumOfLeftLeaves(TreeNode* root) 
    {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};
