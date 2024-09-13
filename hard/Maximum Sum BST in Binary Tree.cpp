class info
    {
        public:
        bool isBST;
        int s;
        int ma;
        int mi;
    };



class Solution 
{
public:


    info msb(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return {1,0,INT_MIN,INT_MAX};
        }

        info l=msb(root->left,ans);
        info r=msb(root->right,ans);

        info res;

        if(l.isBST && r.isBST && l.ma < root->val && r.mi > root->val)
        {
            res.s=r.s+l.s+root->val;
            res.isBST=1;
            res.isBST=1;
            ans=max(ans,res.s);
            res.ma=max(r.ma,root->val);
            res.mi=min(l.mi,root->val);
            return res;
        }

        res.isBST=0;
        res.s=0;
        res.mi=0;
        res.ma=0;
        return res;
        
    }



    int maxSumBST(TreeNode* root) 
    {
        int k=0;
        info r1=msb(root,k);
        return k;
    }
};  
   
