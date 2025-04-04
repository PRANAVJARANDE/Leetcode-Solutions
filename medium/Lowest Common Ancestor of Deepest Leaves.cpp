/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        queue<TreeNode*>q1;
        q1.push(root);
        map<int,queue<TreeNode*>>m;
        map<int,TreeNode*>pr;
        int d=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                auto nn=q1.front();
                m[d].push(nn);
                q1.pop();
                auto lf=nn->left;
                auto rg=nn->right;
                if(lf)
                {
                    pr[lf->val]=nn;
                    q1.push(lf);
                }
                if(rg)
                {
                    pr[rg->val]=nn;
                    q1.push(rg);
                }
            }
            d++;
        }
        auto v1=m[d-1];

        map<int,int>vis;
        
        while(v1.size()>1)
        {
            auto fr=v1.front();
            v1.pop();
            
            auto par=pr[fr->val];
            if(!par)
            {
                return fr;
            }
            if(vis[par->val]==0)
            {
                vis[par->val]=1;
                v1.push(par);
            }
        }
        return v1.front();
    }
};
