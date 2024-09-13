class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        vector<int> v1;

        while(!q1.empty())
        {
            TreeNode* k=q1.front();
            q1.pop();

            if(k!=NULL)
            {
                v1.push_back(k->val);
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                }
            }
            else
            {
                ans.push_back(v1);
                v1.resize(0);
                if(q1.size()>0)
                {
                    q1.push(NULL);
                }
                
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
            
    }
};
