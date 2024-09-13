class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);

        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();

            if(k!=NULL)
            {
                if(q1.front()==NULL)
                {
                    ans.push_back(k->val);
                }
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
                q1.push(NULL);
            }
        }
        return ans;
        
    }
};
