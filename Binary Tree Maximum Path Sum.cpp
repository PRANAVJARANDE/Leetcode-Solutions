class Solution {
public:

    int helper(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;

        int l=max(0,helper(root->left,ans));
        int r=max(0,helper(root->right,ans));

        ans=max(ans,root->val+l+r);
        return max(l,r)+root->val;
    }


    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};
