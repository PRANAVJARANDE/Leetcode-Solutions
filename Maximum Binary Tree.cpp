class Solution {
public:

   
    TreeNode* construct(vector<int> &arr,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }

        int ma=INT_MIN;
        int mi;
        for(int i=l;i<=r;i++)
        {
            if(arr[i]>ma)
            {
                ma=arr[i];
                mi=i;
            }
        }

        TreeNode* root=new TreeNode(ma);
        root->left=construct(arr,l,mi-1);
        root->right=construct(arr,mi+1,r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return construct(nums,0,nums.size()-1); 
    }
};
