class Solution {
public:

    void helper(TreeNode* & root,int &s)
    {
        if(root==NULL)
        {
            return ;
        }
        helper(root->right,s);
        root->val+=s;
        s=root->val;
        helper(root->left,s);
    }

    TreeNode* bstToGst(TreeNode* root) 
    {
        int s=0;
        helper(root,s);
        return root;
    }
};
