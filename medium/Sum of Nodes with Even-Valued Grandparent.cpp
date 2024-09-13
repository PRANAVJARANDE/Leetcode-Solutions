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

    int sumofchild(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int s=0;
        if(root->left!=NULL)
        {
            s+=root->left->val;
        }
        if(root->right!=NULL)
        {
            s+=root->right->val;
        }
        return s;
    }
    
    int sumEvenGrandparent(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int a=0;
        if(root->val%2==0)
        {
            a+=sumofchild(root->left)+sumofchild(root->right);
        }
        return a+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};
