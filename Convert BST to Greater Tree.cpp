class Solution {
public:

    void helper(TreeNode* &root,int &s)
    {
        if(root==NULL)
        {
            return;
        }
        helper(root->right,s);
        s+=root->val;
        root->val=s;
        helper(root->left,s);
    }


    TreeNode* convertBST(TreeNode* root) {
        int s=0;
        helper(root,s);
        return root;
    }
};
