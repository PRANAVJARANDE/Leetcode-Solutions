class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int z) 
    {
        if(root==NULL)
        {
            return 0;
        }
        vector<long long> v1;
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);

        long long s=0;
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
                v1.push_back(s);
                s=0;
                q1.push(NULL);
            }
        }
        v1.push_back(s);
        if(v1.size()<z)
        {
            return -1;
        }
        sort(v1.begin(),v1.end());
        return v1[v1.size()-z];        
    }
};
