class Solution {
public:

    string helper(TreeNode* root,unordered_map<string,int> &m,vector<TreeNode*> &ans)
    {
        if(root==NULL)
        {
            return "";
        }
        string a=to_string(root->val)+","+helper(root->left,m,ans)+","+helper(root->right,m,ans)+",";
        m[a]++;
        if(m[a]==2)
        {
            ans.push_back(root);
        }
        return a;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        helper(root,m,ans);
        return ans;
    }
};
