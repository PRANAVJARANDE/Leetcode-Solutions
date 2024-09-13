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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        int m=INT_MIN;
        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                m=max(m,k->val);
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
                ans.push_back(m);
                m=INT_MIN;
                q1.push(NULL);
            }
            
        }
        ans.push_back(m);
        return ans;
    }
};
