class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int k) 
    {
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==k)
    {
        return root;
    }

    TreeNode * l=searchBST(root->left,k);
    if(l!=NULL)
    {
        return l;
    }
    TreeNode * r=searchBST(root->right,k);
    if(r!=NULL)
    {
        return r;
    }
    return NULL;
    }
};
