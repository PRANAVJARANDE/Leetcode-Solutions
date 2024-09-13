class Solution {
public:
    void flatten(TreeNode* root) 
    {
if(root==NULL)
{
    return;
}
flatten(root->left);
flatten(root->right);

if(root->left==NULL && root->right==NULL)
{
    return;
}
else if(root->left==NULL)
{
    return;
}
else if(root->right==NULL)
{
    root->right=root->left;
    root->left=NULL;
}
else
{
    TreeNode *temp=root->left;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->right=root->right;
    root->right=root->left;
    root->left=NULL;
}


}
};
