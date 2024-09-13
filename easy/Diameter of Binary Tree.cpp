class Solution {
public:

    int heightt(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int h=1+max(heightt(root->left),heightt(root->right));
        return h;
    }


    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        int hd=heightt(root->left)+heightt(root->right);
        int k= max(hd,max(ld,rd));
        return k;
    }
};
