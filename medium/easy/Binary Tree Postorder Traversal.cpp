class Solution {
public:
    
         void getpostorder(vector<int> &v1,TreeNode* root)
        {
            if(root==NULL)
            {
                return;
            }
            
            getpostorder(v1,root->left);
            getpostorder(v1,root->right);
            v1.push_back(root->val);
        }




    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> v1;
        getpostorder(v1,root);
        return v1;
    }
};
