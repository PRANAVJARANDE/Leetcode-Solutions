class Solution {
public:
    bool evaluateTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 1;
        }

        if(root->val==1)
        {
            return 1;
        }
        if(root->val==0)
        {
            return 0;
        }
        bool l=evaluateTree(root->left);
        bool r=evaluateTree(root->right);

        if(root->val==2)
        {
            return (l || r);
        }
        if(root->val==3)
        {
            return (l && r);
        }
        return 1;
    }
};
