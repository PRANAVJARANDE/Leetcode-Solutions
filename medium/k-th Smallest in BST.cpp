/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    int kthSmallest(Node *root, int&k) 
    {
        if(!root)return -1;
        if(root->left)
        {
            int l=kthSmallest(root->left,k);
            if(l!=-1)return l;
        }
        k--;
        if(k==0)return root->data;
        if(root->right)
        {
            int r=kthSmallest(root->right,k);
            if(r!=-1)return r;
        }
        return -1;
    }
};
