class Solution {
public:

    TreeNode* findd(TreeNode*root,int x)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==x)
        {
            return root;
        }
        TreeNode* lf=findd(root->left,x);
        if(lf!=NULL)
        {
            return lf;
        }
        TreeNode* rf=findd(root->right,x);
        if(rf!=NULL)
        {
            return rf;
        }
        return NULL;
    }

    int sz(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ls=sz(root->left);
        int rs=sz(root->right);
        return 1+ls+rs;
    }


    bool btreeGameWinningMove(TreeNode* root, int n, int x) 
    {
        TreeNode* jj=findd(root,x);
        int lp=sz(jj->left);
        int rp=sz(jj->right);
        int rm=n-lp-rp-1;
        
        if(2*max(rm,max(lp,rp))>n)
        {
            return 1;
        }
        return 0;
        
    }
};
