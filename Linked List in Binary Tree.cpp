/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool helper(ListNode*temp,TreeNode* root,ListNode*head)
    {
        if(temp==NULL)return 1;
        if(root==NULL)return 0;
        bool op1=0,op2=0;
        if(temp->val == root->val)return helper(temp->next,root->left,head) || helper(temp->next,root->right,head);
        else if(head->val == root->val)return helper(temp,root->left,head->next) || helper(temp,root->right,head->next);
        else return helper(head,root->left,head) || helper(head,root->right,head);
        
    }



    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head,root,head);
    }
};
