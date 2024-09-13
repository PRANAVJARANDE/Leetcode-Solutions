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


    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        vector<int> v1;
        getinorder(root,v1);

        TreeNode *nh=new TreeNode(v1[0]);
        TreeNode* temp=nh;
        for(int i=1;i<v1.size();i++)
        {
            temp->right=new TreeNode(v1[i]);
            temp=temp->right;
        }

        return nh;

    }
};
