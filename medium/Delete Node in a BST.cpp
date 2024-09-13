class Solution {
public:
    TreeNode* inordersucc(TreeNode *root)
    {
        TreeNode * c=root;
        while(c!=NULL && c->left!=NULL)
        {
            c=c->left;
        }
        return c;
    }


    TreeNode* deleteNode(TreeNode* root, int k) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        

        if(k < root->val)
        {
            root->left=deleteNode(root->left,k);
        }
        else if(k > root->val)
        {
            root->right=deleteNode(root->right,k);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                return NULL;
            }
            if(root->right==NULL)
            {
                return root->left;
            }
            if(root->left==NULL)
            {
                return root->right;
            }
            TreeNode *n=inordersucc(root->right);
            swap(n->val,root->val);
            root->right=deleteNode(root->right,n->val);
            return root;
        }
        return root;
        
       
    }
};
