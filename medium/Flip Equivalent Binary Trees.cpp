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

    bool helper(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)return 1;
        if(root1==NULL)return 0;
        if(root2==NULL)return 0;
        int v1=root1->val;
        int v2=root2->val;
        if(v1!=v2)return 0;
        int l1=-1,r1=-1,l2=-1,r2=-1;
        if(root1->left)l1=root1->left->val;
        if(root1->right)r1=root1->right->val;
        if(root2->left)l2=root2->left->val;
        if(root2->right)r2=root2->right->val;
        if(l1==l2 && r1==r2)
        {
            bool lf=helper(root1->left,root2->left);
            bool rf=helper(root1->right,root2->right);
            return (lf && rf);
        }
        if(l1==r2 && l2==r1)
        {
            bool lf=helper(root1->left,root2->right);
            bool rf=helper(root1->right,root2->left);
            return (lf && rf);
        }
        return 0;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        return helper(root1, root2);
    }
};
