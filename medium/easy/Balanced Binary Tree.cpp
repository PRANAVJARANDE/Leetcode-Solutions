class Solution 
{
public:

    int heightt(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(heightt(root->left),heightt(root->right));
    }

    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 1;
        }



        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);

        if(abs(heightt(root->left)-heightt(root->right))<=1 && l==1 && r==1)
        {
            return 1;
        }
        return 0;

    }
};
