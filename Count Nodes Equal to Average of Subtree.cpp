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

    pair<int,int> helper(TreeNode* root,int &count)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> l=helper(root->left,count);
        pair<int,int> r=helper(root->right,count);
        int n=1+l.second+r.second;
        int s=root->val+l.first+r.first;
        float avg=s/n;
        if(avg==root->val)
        {
            count++;
        }
        return {s,n};
    }

    int averageOfSubtree(TreeNode* root) 
    {
        int count=0;
        helper(root,count);
        return count;
    }
};
