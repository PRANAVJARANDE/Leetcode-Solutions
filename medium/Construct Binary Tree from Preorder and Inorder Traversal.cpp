class Solution {
public:
    int i;
    Solution()
    {
        i=0;
    }

    int getindex(vector<int> v1,int k)
    {
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==k)
            {
                return i;
            }
        }
        return 0;
    }


    TreeNode* helper(vector<int> pre,vector<int> ino,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        
        int k=pre[i];
        TreeNode* root=new TreeNode(k);
        i++;

        int ind=getindex(ino,k);  
        root->left=helper(pre,ino,l,ind-1);
        root->right=helper(pre,ino,ind+1,r);
        return root;
    }



    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) 
    {
        return helper(pre,ino,0,pre.size()-1);
    }
};
