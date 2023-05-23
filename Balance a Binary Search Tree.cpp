class Solution {
public:

void getnod(TreeNode* root , vector<int> &v1)
{
    if(root==NULL)
    {
        return;
    }
    getnod(root->left,v1);
    v1.push_back(root->val);
    getnod(root->right,v1);
}

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


TreeNode* balanceBST(TreeNode* root) 
{
    vector<int> v1;
    getnod(root,v1);
    TreeNode* tn=construct(v1,0,v1.size()-1);  
    return tn;
}

};
