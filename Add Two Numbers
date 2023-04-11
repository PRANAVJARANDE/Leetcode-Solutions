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
class Solution
{
public:

void insertt(ListNode * &head,int val)
{
    ListNode*temp=head;
    ListNode* n=new ListNode(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

int lengthh(ListNode *head)
    {
        int k=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            k++;
            temp=temp->next;
        }
        return k;
    }





    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {

        int j1=lengthh(l1);
        int j2=lengthh(l2);


        ListNode *head=new ListNode(-1);
        ListNode *ptr1;
        ListNode *ptr2;


        if(j1>=j2)
        {
            ptr1=l1;
            ptr2=l2;
        }
        else
        {
            ptr1=l2;
            ptr2=l1;
        }





        



        int carr=0,ans;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            
            int h=ptr1->val + ptr2->val;

            if(ptr1->next==NULL)
            {
                if(h>=10)
                {
                insertt(head,h%10);
                insertt(head,1);
                return head->next;
                }
            }







            if(h>=10 && ptr1->next!=NULL)
            {
                ptr1->next->val++;
                ans=h%10;
            }
            else
            {
                ans=h;
            }

            insertt(head,ans);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
              
        }

        while(ptr1!=NULL)
        {
            int h=ptr1->val;
           
            if(ptr1->next==NULL)
            {
                if(h>=10)
                {
                insertt(head,h%10);
                insertt(head,1);
                break;
                }
            }
            
            if(h>=10)
            {
                ptr1->next->val++;
                ans=h%10;
            }
            else
            {
                ans=h;
            }

            
            
            insertt(head,ans);
            ptr1=ptr1->next;
        }

      



        return head->next;
    }
};
