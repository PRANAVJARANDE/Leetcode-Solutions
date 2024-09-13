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
    bool isCompleteTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 1;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);

        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                }
                if(k->left==NULL && k->right!=NULL)
                {
                    return 0;
                }
                else if(k->left==NULL && k->right==NULL)
                {
                    break;
                }
                else if(k->left!=NULL && k->right==NULL)
                {
                    break;
                }
            }
            else if(!q1.empty())
            {
                q1.push(NULL);
            }

        }
          while(!q1.empty())
            {
                if(q1.front()==NULL)
                {
                    q1.pop();
                    continue;
                }
                auto k=q1.front();
                if(k->left!=NULL || k->right!=NULL)
                {
                    return 0;
                }
                q1.pop();
            }
            return 1;
        
    }
};
