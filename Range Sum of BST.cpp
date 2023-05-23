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


    int rangeSumBST(TreeNode* root, int l, int h) 
    {
        vector<int> v1;
        getnod(root,v1);
        int s=0;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]>=l && v1[i]<=h)
            {
                s=s+v1[i];
            }
        }
        return s;
    }
};
