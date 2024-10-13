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
    vector<int> ans;
    vector<int> helper(TreeNode* root)
    {
        if(root==NULL)return {1,0};
        vector<int> l=helper(root->left);
        vector<int> r=helper(root->right);
        if(l[0] && r[0] && l[1]==r[1])
        {
            ans.push_back(l[1]+r[1]+1);
            return {1,l[1]+r[1]+1};
        }
        return {0,l[1]+r[1]+1};
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        helper(root);
        sort(ans.begin(),ans.end(),greater<int>());
        k--;
        if(k<(int)ans.size())
        {
            return ans[k];
        }
        return -1;        
    }
};
