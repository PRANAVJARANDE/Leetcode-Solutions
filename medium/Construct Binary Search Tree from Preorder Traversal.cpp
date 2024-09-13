class Solution {
public:

    TreeNode* construct(queue<int> &q1,TreeNode*mi,TreeNode*ma)
    {
        if(q1.empty())
        {
            return NULL;
        }
        if(mi!=NULL && mi->val > q1.front())
        {
            return NULL;
        }
        if(ma!=NULL && ma->val < q1.front())
        {
            return NULL;
        }
        int k=q1.front();
        q1.pop();
        TreeNode *root=new TreeNode(k);
        root->left=construct(q1,mi,root);
        root->right=construct(q1,root,ma);

        return root;
    }



    TreeNode* bstFromPreorder(vector<int>& v1) 
    {
        queue<int> q1;
        for(int i=0;i<v1.size();i++)
        {
            q1.push(v1[i]);
        }
        TreeNode* nh=construct(q1,NULL,NULL);
        return nh;
    }
};
