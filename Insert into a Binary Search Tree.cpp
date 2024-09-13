class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int k) 
    {
        if(root==NULL)
        {
            TreeNode *n=new TreeNode(k);
            return n;
        }

        if(k < root->val)
        {
            root->left=insertIntoBST(root->left,k);
        }
        else
        {
            root->right=insertIntoBST(root->right,k);
        }
        return root;
    }
};
