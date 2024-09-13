class Solution {
public:

    vector<TreeNode*> getcomb(int s,int e)
    {
        vector<TreeNode*>ans ;
        if(s>e)
        {
            ans.push_back(NULL);
            return ans;
        }

        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*> lgc=getcomb(s,i-1);
            vector<TreeNode*> rgc=getcomb(i+1,e);

            for(int j=0;j<lgc.size();j++)
            {
                TreeNode* l=lgc[j];
                for(int k=0;k<rgc.size();k++)
                {
                    TreeNode* r=rgc[k];
                    TreeNode *root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }



    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> ans=getcomb(1,n);
        return ans;
    }
};
