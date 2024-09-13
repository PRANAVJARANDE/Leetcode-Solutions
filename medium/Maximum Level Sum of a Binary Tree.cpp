class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        int l=1,s=0,smax=INT_MIN,ans=0;
        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                s=s+k->val;
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

            if(k==NULL)
            {
                if(s>smax)
                {
                    smax=s;
                    ans=l;
                }
                s=0;
                l++;
            }
        }
        return ans;
        
    }
};
