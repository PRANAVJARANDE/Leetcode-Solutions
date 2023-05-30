class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }

        invertTree(root->right);
        invertTree(root->left);

        swap(root->left,root->right);
        return root;
    }
};
