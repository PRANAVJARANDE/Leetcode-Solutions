class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int l, int h) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val > l && root->val > h)
        {
            return trimBST(root->left,l,h);
        }
        else if(root->val < l && root->val < h)
        {
            return trimBST(root->right,l,h);
        }
        else
        {
            root->left=trimBST(root->left,l,h);
            root->right=trimBST(root->right,l,h);
            return root;
        }
        return root;

        
    }
};
