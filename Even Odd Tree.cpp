class Solution {
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 1;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);

        int level=0;
        int ma=INT_MIN;
        int mi=INT_MAX;

        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                if(level%2==0)
                {
                    if(k->val%2==0)
                    {
                        return 0;
                    }
                    if(k->val<=ma)
                    {
                        return 0;
                    }
                    ma=max(ma,k->val);
                }
                if(level%2==1)
                {
                    if(k->val%2==1)
                    {
                        return 0;
                    }
                    if(k->val>=mi)
                    {
                        return 0;
                    }
                    mi=min(mi,k->val);
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
                ma=INT_MIN;
                mi=INT_MAX;
                level++;
                q1.push(NULL);
            }
        }
        return 1;
        
    }
};
