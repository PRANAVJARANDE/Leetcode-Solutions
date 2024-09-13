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

    bool tdfind(vector<int>& a, int k) {
        return binary_search(a.begin(), a.end(), k);
    }

    vector<TreeNode*> ans;
    TreeNode* helper(TreeNode* root,vector<int>& td)
    {
        if(root==NULL)return NULL;
        
        TreeNode* le=helper(root->left,td);
        TreeNode* ri=helper(root->right,td);
        if(tdfind(td,root->val))
        {
            if(le!=NULL) ans.push_back(le);
            if(ri!=NULL) ans.push_back(ri);
            return NULL;
        }
        root->left=le;
        root->right=ri;
        return root;
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        sort(td.begin(),td.end());
        
        TreeNode* h1=helper(root,td);
        if(!tdfind(td,root->val))
        {
            ans.push_back(h1);
        }
        return ans;
    }
};
