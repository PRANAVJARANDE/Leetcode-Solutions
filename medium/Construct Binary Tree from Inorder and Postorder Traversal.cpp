class Solution 
{
public:
    int searchh(vector<int> ino,int k,int l,int r)
    {
        for(int i=l;i<=r;i++)
        {
            if(ino[i]==k)
            {
                return i;
            }
        }
        return 0;
    }

    TreeNode* helper(vector<int>&ino, vector<int>&post, int l, int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int jk=post.back();
        post.pop_back();

        TreeNode* root=new TreeNode(jk);

        int inn=searchh(ino,jk,l,r);
        root->right=helper(ino,post,inn+1,r);
        root->left=helper(ino,post,l,inn-1);
        
        return root;
    }



    

    TreeNode* buildTree(vector<int>& ino, vector<int>& post) 
    {
        int n=ino.size();
        return helper(ino,post,0,n-1);
    }

};
