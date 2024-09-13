class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }

        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        int ans=root->val;
        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();

            if(k!=NULL)
            {
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                }
            }
            else if(!q1.empty())
            {
                ans=q1.front()->val;
                q1.push(NULL);
            }
        }

        return ans;
        
    }
};
