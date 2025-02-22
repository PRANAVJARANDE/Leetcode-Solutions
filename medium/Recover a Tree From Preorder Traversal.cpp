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

    int in;
    TreeNode* build(int d,vector<vector<int>>&v1)
    {
        int sz=v1.size();
        if(in>=sz)
        {
            return NULL;
        }
        TreeNode* root=NULL;
        if(d==v1[in][1])
        {
            root=new TreeNode(v1[in][0]);
            in++;
            root->left=build(d+1,v1);
            root->right=build(d+1,v1);
        }
        return root;
    }

    TreeNode* recoverFromPreorder(string s) 
    {
        vector<vector<int>>v1;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='-')cnt++;
            else
            {
                int num=0;
                while(i<s.size() && s[i]!='-')
                {
                    num*=10;
                    num+=s[i]-'0';
                    i++;
                }
                i--;
                v1.push_back({num,cnt});
                cnt=0;
            }
        }        
        in=0;
        auto ans=build(0,v1);
        return ans;
    }
};
