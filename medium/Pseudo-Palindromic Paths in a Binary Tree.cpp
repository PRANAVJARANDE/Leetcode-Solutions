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

    int helper(TreeNode* root,int sz,vector<int>&vis)
    {
        if(root==NULL)
            return 0;
        
        if(root->right==NULL && root->left==NULL)
        {
            sz++;
            vis[root->val]++;
            int cnt=0;
            for(int i=1;i<=9;i++)
            {
                if(vis[i]%2)
                {
                    cnt++;
                }
            }
            vis[root->val]--;
            if(sz%2)
            {
                if(cnt==1) return 1;
                else return 0;
            }
            else    
            {
                if(cnt==0) return 1;
                return 0;
            }
        }
        int ans=0;
        vis[root->val]++;
        ans+=helper(root->left,sz+1,vis);
        ans+=helper(root->right,sz+1,vis);
        vis[root->val]--;
        return ans;
    }

    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> vis(10,0);
        return helper(root,0,vis);
    }
};
