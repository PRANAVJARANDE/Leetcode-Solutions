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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        string a,b;
        ListNode* temp=l1;
        while(temp!=NULL)
        {
            a.push_back(temp->val+'0');
            temp=temp->next;
        }
        temp=l2;
        while(temp!=NULL)
        {
            b.push_back(temp->val+'0');
            temp=temp->next;
        }
        int l=a.size()-1,r=b.size()-1;
        ListNode* res=NULL;
        int carry=0;
        while(l>=0 || r>=0 || carry==1)
        {
            int c=carry;
            if(l>=0)
            {
                c+=a[l]-'0';
                l--;
            }
            if(r>=0)
            {
                c+=b[r]-'0';
                r--;
            }
            ListNode* temp=new ListNode(c%10);
            temp->next=res;
            res=temp;
            carry=c/10;
        }
        return res;
    }
};
