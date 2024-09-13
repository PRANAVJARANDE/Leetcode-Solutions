class Solution {
public:

    bool findd(TreeNode* root,TreeNode* k,vector<TreeNode*> &v1)
    {
        if(root==NULL)
        {
            return 0;
        }
        v1.push_back(root);
        bool lf=findd(root->left,k,v1);
        bool rf=findd(root->right,k,v1);

        if(lf==1 || rf==1)
        {
            return 1;
        }
        if(k==root)
        {
            return 1;
        }
        v1.pop_back();
        return 0;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
            if(root==NULL)
            {
                return NULL;
            }   

            vector<TreeNode*> a1;
            findd(root,p,a1);
            vector<TreeNode*> a2;
            findd(root,q,a2);

            int m=min(a1.size(),a2.size());

            int h=m-1;
            while(h>=0)
            {
                if(a1[h]==a2[h])
                {
                    return a1[h];
                }
                h--;
            }
            return NULL;

    }
};
