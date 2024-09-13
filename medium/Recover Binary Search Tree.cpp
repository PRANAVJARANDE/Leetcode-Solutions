class Solution {
public:

    void helper(TreeNode* root,TreeNode* &f1,TreeNode* &f2,TreeNode* &prev)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->left,f1,f2,prev);
        if(prev!=NULL && root->val < prev->val)
        {
            if(f1==NULL)
            {
                f1=prev;
                f2=root;
            }
            else
            {
                f2=root;
            }
        }
        prev=root;
        helper(root->right,f1,f2,prev);
    }

    void recoverTree(TreeNode* root) 
    {
        TreeNode* f1=NULL;
        TreeNode* f2=NULL;
        TreeNode* prev=NULL;
        helper(root,f1,f2,prev);
        swap(f1->val,f2->val);
    }
};
