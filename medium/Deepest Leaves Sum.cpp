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
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        int s=0;
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
                s=0;
                q1.push(NULL);
            }
        }
        return s;

        
    }
};
