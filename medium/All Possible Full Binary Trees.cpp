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


    vector<TreeNode*> helper(int n,unordered_map<int,vector<TreeNode*>> &m)
    {
        vector<TreeNode*> ans;
        
        if(n%2==0 || n<0)
        {
            return ans;
        }
        
        if(m.find(n)!=m.end())
        {
            return m[n];
        }

        if(n==1)
        {
            ans.push_back(new TreeNode(0));
            return m[1]=ans;
        }

        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> ll=helper(i,m);
            vector<TreeNode*> rr=helper(n-i-1,m);
            for(int i=0;i<ll.size();i++)
            {
                for(int j=0;j<rr.size();j++)
                {
                    TreeNode* n=new TreeNode(0);
                    n->left=ll[i];
                    n->right=rr[j];
                    ans.push_back(n);
                }
            }
        }
        return m[n]=ans;
    }



    vector<TreeNode*> allPossibleFBT(int n) 
    {
        unordered_map<int,vector<TreeNode*>> m;
        return  helper(n,m);
    }
};
