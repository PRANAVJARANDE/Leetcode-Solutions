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
    int res;
    int dist;
    vector<int> helper(TreeNode* root)
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int>le=helper(root->left);
        vector<int>re=helper(root->right);
        for(int x:le)
            if(x+1<=10)ans.push_back(x+1);
            
        for(int x:re)
            if(x+1<=10)ans.push_back(x+1);
        
        for(int x: le)
        {
            for(int y:re)
            {
                if(x+y+2<=dist)res++;
            }
        }
        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        res=0;
        dist=distance;
        helper(root);
        return res;
    }
};
