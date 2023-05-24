class Solution 
{
public:

    void getinorder(TreeNode* root,vector<int> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        getinorder(root->left,v1);
        v1.push_back(root->val);
        getinorder(root->right,v1);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> arr,ans,temp;
        getinorder(root,arr);

        int amax=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            int k=0;
            for(int j=i;j<arr.size();j++)
            {
                if(arr[i]==arr[j])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            temp.push_back(k);
            amax=max(amax,k);
        }
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==amax)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
