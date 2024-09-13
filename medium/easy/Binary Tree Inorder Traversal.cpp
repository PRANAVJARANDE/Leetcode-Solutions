class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v1);
        v1.push_back(root->val);
        inorder(root->right,v1);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v1;
        inorder(root,v1);
        return v1;        
    }
};
