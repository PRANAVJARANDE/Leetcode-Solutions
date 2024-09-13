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


    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> v1;
        getnod(root,v1);

        int m=INT_MAX;
        for(int i=1;i<v1.size();i++)
        {
            m=min(m,v1[i]-v1[i-1]);
        }
        return m;   
    }
}
