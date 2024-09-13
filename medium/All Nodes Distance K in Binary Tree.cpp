/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> v1;

    void pushme(TreeNode* root,int k)
    {
        if(root==NULL)
        {
            return;
        }
        if(k==0)
        {
            v1.push_back(root->val);
            return;
        }
        pushme(root->left,k-1);
        pushme(root->right,k-1);
    }


    int helper(TreeNode* root,TreeNode* t,int k)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root==t)
        {
            pushme(root,k);
            return 1;
        }
        int l=helper(root->left,t,k);
        if(l!=0)
        {
            if(l==k)
            {
                v1.push_back(root->val);
            }
            else if(l<k)
            {
                pushme(root->right,k-l-1);
            }
            return l+1;
        }
        int r=helper(root->right,t,k);
        if(r!=0)
        {
            if(r==k)
            {
                v1.push_back(root->val);
            }
            else if(r<k)
            {
                pushme(root->left,k-r-1);
            }
            return r+1;
        }
        return 0;
    }


    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) 
    {
        helper(root,t,k);
        return v1;
    }
};
