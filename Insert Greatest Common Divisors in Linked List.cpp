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
        
        int gcd(int a,int b)
        {
                int j=min(a,b);
                while(j>0)
                {
                        if(a%j==0 && b%j==0)
                        {
                                return j;
                        }
                        j--;
                }
                return 1;
        }
        
        
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
            ListNode* temp=head;
            ListNode* k;
            while(temp->next!=NULL)
            {
                ListNode* n=new ListNode(gcd(temp->val,temp->next->val));
                k=temp->next;
                temp->next=n;
                n->next=k;
                temp=k;
            }
            return head;
    }
};
