class Solution {
public:

    int s;
    Solution()
    {
        s=0;
    }
    bool hasPathSum(TreeNode* root, int t) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL && s==t-root->val)
        {
            return 1;
        }
        

        s=s+root->val;
        bool l=hasPathSum(root->left,t);
        bool r=hasPathSum(root->right,t);

        s=s-root->val;

        if((l==1 || r==1))
        {
            return 1;
        }
        return 0;


        
    }
};
