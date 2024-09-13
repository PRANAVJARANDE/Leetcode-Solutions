class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL && root2==NULL)
        {
            return 1;
        }
        if((root1!=NULL && root2==NULL) || (root1==NULL && root2!=NULL))
        {
            return 0;
        }
    
        return (root1->val == root2->val && isSameTree(root1->right,root2->right) && isSameTree(root1->left,root2->left)  );
      
    }
};
