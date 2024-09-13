class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int h=1+max(maxDepth(root->left),maxDepth(root->right));
        return h;
    }
};
