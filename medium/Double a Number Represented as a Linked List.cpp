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
class Solution {
public:
        
    pair<ListNode*,int> helper(ListNode* head)
    {
        if(head->next==NULL)
        {
                int k=2*(head->val);
                return {new ListNode(k%10),k/10};
        }
            
        pair<ListNode*,int> p1=helper(head->next);
        
        int k=(2*(head->val))+p1.second;
        ListNode* n=new ListNode(k%10);
        n->next=p1.first;
        return {n,k/10};
    }
        
        
        
    ListNode* doubleIt(ListNode* head) 
    {
           pair<ListNode* ,int> p1=helper(head);
           if(p1.second!=0)
           {
                ListNode* n=new ListNode(p1.second);
                n->next=p1.first;
                return n;
           }
                return p1.first;
            
            
    }
};
