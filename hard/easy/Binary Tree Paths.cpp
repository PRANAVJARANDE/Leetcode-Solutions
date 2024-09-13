class Solution {
public:

    void helper(TreeNode* root,vector<string>&ans,string h)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            h=h+to_string(root->val);
            ans.push_back(h);
            return ;
        }
        h=h+to_string(root->val)+"->";
        helper(root->left,ans,h);
        helper(root->right,ans,h);
        
    }


    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string h="";
        vector<string> ans;
        helper(root,ans,h);
        return ans;
    }
};
