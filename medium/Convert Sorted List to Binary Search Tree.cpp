class Solution {
public:

 

    void getpq(ListNode* head,vector<int> &v1 )
    {
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v1.push_back(temp->val);
            temp=temp->next;
        }
    }


TreeNode* construct(vector<int> v1,int l, int r)
{
    if(l>r)
    {
        return NULL;
    }
    int mid=(l+r)/2;
    TreeNode *root=new TreeNode(v1[mid]);
    root->left=construct(v1,l,mid-1);
    root->right=construct(v1,mid+1,r);
    return root;
}


    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int> v1;
        getpq(head,v1);
        TreeNode * nh=construct(v1,0,v1.size()-1);
        return nh;
    }
};
