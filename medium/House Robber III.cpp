class Solution {
public:

    int helper(TreeNode* root,unordered_map<TreeNode*, int>& dp)
    {
        if(root==NULL)
            return 0;

        if(dp.count(root))
            return dp[root];

        int ans=0;
        if(root->left)
            ans+=helper(root->left->left,dp)+helper(root->left->right,dp);

        if(root->right)
            ans+=helper(root->right->left,dp)+helper(root->right->right,dp);
        
        return dp[root]=max(root->val+ans,helper(root->left,dp)+helper(root->right,dp));
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return helper(root,dp);
    }
};

class Solution {
public:


    int helper(TreeNode* root,bool b)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(b==0)
        {
            int rb=root->val+helper(root->left,1)+helper(root->right,1);
            int nr=helper(root->left,0)+helper(root->right,0);
            return max(rb,nr);
        }
        return helper(root->left,0)+helper(root->right,0);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return max(helper(root,0),helper(root,1));
    }
};
