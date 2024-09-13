class Solution {
public:

    void getinorder(TreeNode* root,vector<int> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        getinorder(root->left,v1);
        v1.push_back(root->val);
        getinorder(root->right,v1);
    }

    int minDiffInBST(TreeNode* root) 
    {
        vector<int> v1;
        getinorder(root,v1);
        int m=INT_MAX;
        for(int i=1;i<v1.size();i++)
        {
            m=min(v1[i]-v1[i-1],m);
        }
        return m;
    }
};
