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

    void helper(TreeNode* root,map<int,map<int,vector<int>>> &m,int ind,int l)
    {
        if(root==NULL)
        {
            return;
        }
        m[ind][l].push_back(root->val);
        helper(root->left,m,ind-1,l+1);
        helper(root->right,m,ind+1,l+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,vector<int>>> m;
        helper(root,m,0,0);
        vector<vector<int>> ans;
        for(auto x: m)
        {
            vector<int> v1;
            for(auto y: x.second)
            {
                sort(y.second.begin(),y.second.end());
                for(auto jj: y.second)
                {
                    v1.push_back(jj);
                }
            }
            ans.push_back(v1);
        }
        return ans;
    }
};
