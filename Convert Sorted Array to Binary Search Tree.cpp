class Solution {
public:

TreeNode* construct(vector<int> v1,int l, int r)
{
    if(l>r)
    {
        return NULL;
    }
    int mid=(l+r)/2;
    TreeNode *root=new TreeNode(v1[mid]);
    root->left=construct(v1,l,mid-1);
    root->right=construct(v1,mid+1,r);
    return root;
}


    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {

        return construct(nums,0,nums.size()-1);
    }
   
