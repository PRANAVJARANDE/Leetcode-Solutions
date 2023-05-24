class BSTIterator 
{
public:

    int i;
    TreeNode* root;
    queue<int> arr;


    void getinorder(TreeNode* root,queue<int> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        getinorder(root->left,v1);
        v1.push(root->val);
        getinorder(root->right,v1);
    }



    BSTIterator(TreeNode* r) 
    {
        i=-1;
        root=r;
        getinorder(root,arr);
    }

    


    int next() 
    {
        int k=arr.front();
        arr.pop();
        return k;
    }
    
    bool hasNext() 
    {
       if(arr.empty())
       {
           return 0;
       }
       return 1;
    }
};
