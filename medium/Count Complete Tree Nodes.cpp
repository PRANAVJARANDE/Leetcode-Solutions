class Solution {
public:
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int lc=countNodes(root->left);
        int rc=countNodes(root->right);
        return 1+lc+rc;
    }
};
