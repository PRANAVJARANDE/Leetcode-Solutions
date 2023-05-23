class Solution {
public:

    void getinorder(TreeNode* root,vector<int> & v1)
    {
        if(root==NULL)
        {
            return;
        }
        getinorder(root->left,v1);
        v1.push_back(root->val);
        getinorder(root->right,v1);
    }


    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> v1;
        getinorder(root,v1);
        return v1[k-1];
    }
};
