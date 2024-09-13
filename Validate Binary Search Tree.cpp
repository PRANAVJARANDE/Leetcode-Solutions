class Solution {
public:

    bool checkk(TreeNode* root,TreeNode*mi,TreeNode* ma)
    {
        if(root==NULL)
        {
            return 1;
        }
       

        if(mi!=NULL && mi->val >= root->val)
        {
            return 0;
        }
        if(ma!=NULL && ma->val <= root->val)
        {
            return 0;
        }
        bool bl=checkk(root->left,mi,root);
        bool br=checkk(root->right,root,ma);

        if(bl && br)
        {
            return 1;
        }
        return 0;

    }




    bool isValidBST(TreeNode* root) 
    {
        return checkk(root,NULL,NULL);
    }
};
