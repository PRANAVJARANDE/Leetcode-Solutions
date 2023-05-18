class Solution {
public:
    
        void getpreorder(vector<int> &v1,TreeNode* root)
        {
            if(root==NULL)
            {
                v1.push_back(INT_MIN);
                return;
            }
            v1.push_back(root->val);
            getpreorder(v1,root->left);
            getpreorder(v1,root->right);
        }

        void getpostorder(vector<int> &v1,TreeNode* root)
        {
            if(root==NULL)
            {
                v1.push_back(INT_MIN);
                return;
            }
            getpostorder(v1,root->left);
            getpostorder(v1,root->right);
            v1.push_back(root->val);
        }

    bool isSymmetric(TreeNode* root) 
    {
        vector<int> v1;
        vector<int> v2;

        getpreorder(v1,root);
        getpostorder(v2,root);

        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[v1.size()-i-1])
            {
                return 0;
            }
        }
        return 1;

    }
};
