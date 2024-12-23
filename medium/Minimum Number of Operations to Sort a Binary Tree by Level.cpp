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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int ans=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            int in=0;
            vector<pair<int,int>>v1;
            while(sz--)
            {
                auto fr=q1.front();
                q1.pop();
                v1.push_back({fr->val,in++});
                if(fr->left)q1.push(fr->left);
                if(fr->right)q1.push(fr->right);
            }
            vector<int>vis(in,0);
            sort(v1.begin(),v1.end());
        
            for(int i=0;i<in;i++) 
            {
                if(vis[i] || v1[i].second==i)continue;
                int cnt=0;
                int j=i;
                while(!vis[j])
                {
                    vis[j]=1;
                    j=v1[j].second;
                    cnt++;
                }
                if(cnt>1)ans+=cnt-1;
            }
        }
        return ans;
    }
};
