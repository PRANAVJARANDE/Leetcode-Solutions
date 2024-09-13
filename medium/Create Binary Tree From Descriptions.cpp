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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int,TreeNode*> m;
        map<int,int>vis;
        for(auto x:desc)
        {
            if(vis[x[0]]==0)
            {
                vis[x[0]]=1;
                m[x[0]]=new TreeNode(x[0]);
            }
            if(vis[x[1]]==0)
            {
                vis[x[1]]=1;
                m[x[1]]=new TreeNode(x[1]);
            }
        }
        for(auto x:desc)
        {
            if(x[2])
            {
                m[x[0]]->left=m[x[1]];
            }
            else
            {
                m[x[0]]->right=m[x[1]];
            }
            vis[x[1]]=0;
        }
        for(auto x: vis)
        {
            if(x.second)
            {
                return m[x.first];
            }
        }
        return nullptr;  
    }
};
