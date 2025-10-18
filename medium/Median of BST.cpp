/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    int helper(Node* root,int&k)
    {
        if(!root)return -1;
        if(root->left)
        {
            int l=helper(root->left,k);
            if(l!=-1)return l;
        }
        k--;
        if(k==0)return root->data;
        if(root->right)
        {
            int r=helper(root->right,k);
            if(r!=-1)return r;
        }
        return -1;
    }
    
    int gettot(Node* root)
    {
        if(!root)return 0;
        int ans=1+gettot(root->left)+gettot(root->right);
        return ans;
    }
  
    int findMedian(Node* root) 
    {
        int n=gettot(root);
        int mid=((n+1)/2);
        return helper(root,mid);
    }
};
