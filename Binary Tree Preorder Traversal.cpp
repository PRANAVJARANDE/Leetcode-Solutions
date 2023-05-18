class Solution {
public:

        void getpreorder(vector<int> &v1,TreeNode* root)
        {
            if(root==NULL)
            {
                return;
            }
            v1.push_back(root->val);
            getpreorder(v1,root->left);
            getpreorder(v1,root->right);
        }


    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> v1;
        getpreorder(v1,root);
        return v1;
    }
};
