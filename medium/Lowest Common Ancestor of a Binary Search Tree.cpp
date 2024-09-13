class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode* l;
        if(p->val < root->val && q->val < root->val)
        {
            l=lowestCommonAncestor(root->left,p,q);
        }
        else if(p->val > root->val && q->val > root->val)
        {
            l=lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return root;
        }
        return l;
    }
};
